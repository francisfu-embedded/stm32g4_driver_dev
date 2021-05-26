//******************************************************************************
// rcc.h
// Author: Yuqi Fu
// Description:
// Driver source file for Reset and Clock Control module for stm32f446re
// - The current driver takes HSE bypass as clock source (will need to switch
// to HSE Crystal when put on a pcb) and generates a 180MHz pll as main clock source
// - The current version of driver does not support the use of internal RC oscillator
// or any low-speed clocks
// - More functionalities may be added in future depending on the application
//*******************************************************************************
#include "rcc.h"

//-------------------------------------------------------------------------------
//Definitions & Macros
//-------------------------------------------------------------------------------

//control register (cr) bit fields
#define RCC_CR_HSION_ON				(1ul << 0u)
#define RCC_CR_HSION_OFF			(0ul << 0u)
#define RCC_CR_HSIRDY				(1ul << 1u)

#define RCC_CR_HSEON_ON				(1ul << 16u)
#define RCC_CR_HSEON_OFF			(0ul << 16u)
#define RCC_CR_HSERDY				(1ul << 17u)
#define RCC_CR_HSEBYP_ON			(1ul << 18u)
#define RCC_CR_HSEBYP_OFF			(0ul << 18u)

#define RCC_CR_PLLON_ON				(1ul << 24u)
#define RCC_CR_PLLON_OFF			(0ul << 24u)
#define RCC_CR_PLLRDY				(1ul << 25u)

#define RCC_CR_HSE_BYPASSED			(RCC_CR_HSEON_ON|RCC_CR_HSEBYP_ON)


#define RCC_CR_HSE_CRYSTAL			(RCC_CR_HSEON_ON|RCC_CR_HSEBYP_OFF)


//pll config regs bit fields, pllclk_fre = crystal_freq * N/M /P
#define RCC_PLLCFGR_PLLM			4ul			            //divides the 8MHz clock by 8, getting 1MHz
#define RCC_PLLCFGR_PLLN			(180ul << 6u)			//vco freq times 360
#define RCC_PLLCFGR_PLLP			(0ul << 16u)			//divide by 2, getting 180MHz output
#define RCC_PLLCFGR_PLLSRC			(1ul << 22u)			//using HSE
#define RCC_PLLCFGR_PLLQ			(2ul << 24u)            //unused dummy value
#define RCC_PLLCFGR_PLLR			(2ul << 28u)			//unused dummy value

#define RCC_PLLCFGR_SETUP           (RCC_PLLCFGR_PLLM|RCC_PLLCFGR_PLLN|RCC_PLLCFGR_PLLP|\
									RCC_PLLCFGR_PLLSRC|RCC_PLLCFGR_PLLQ)

#define RCC_CFGR_SW_PLLP			(2ul << 0u)				//use pllp as system clock
#define RCC_CFGR_PPRE1_APB1_DIV4	(5ul << 10u)			//APB2 & APB2 clock divide by 4
#define RCC_CFGR_PPRE2_APB2_DIV4	(5ul << 13u)
#define RCC_CFGR_SETUP				(RCC_CFGR_SW_PLLP|RCC_CFGR_PPRE1_APB1_DIV4|\
									RCC_CFGR_PPRE2_APB2_DIV4)

#define RCC_APB1ENR_PWREN_ON		(1ul << 28u)

//definitions for PWR registers

#define PWR_CR_ODEN_ON				(1ul << 16u)
#define PWR_CR_ODSWEN_ON			(1ul << 17u)
//#define PWR_CR_VOS_

#define PWR_CSR_ODRDY_ON			(1ul << 16u)
#define PWR_CSR_ODSWRDY_ON			(1ul << 17u)

//definitions for FLASH registers
#define FLASH_ACR_LATENCY           (5ul << 0u)



//-------------------------------------------------------------------------------
//global variables
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------
//local variables
//-------------------------------------------------------------------------------

//
// rcc_reg_set *rcc_regs provides the pointer to the base address of the rcc block
// registers will be accessed using this structure pointer in this way:
// i.e. rcc_regs->rcc_cr = what_ever_uint32_val
//

local rcc_reg_set *rcc_regs = (rcc_reg_set *) RCC_BASE_ADDR;
local pwr_reg_set *pwr_regs = (pwr_reg_set *) PWR_BASE_ADDR;
local flash_reg_set *flash_regs = (flash_reg_set *) FLASH_BASE_ADDR;

//-------------------------------------------------------------------------------
//function prototypes
//-------------------------------------------------------------------------------

void rcc_pwr_enable(void);
void rcc_system_clk_config(bool hse_bypassed);

//-------------------------------------------------------------------------------
//local functions
//-------------------------------------------------------------------------------




//-------------------------------------------------------------------------------
//global functions
//-------------------------------------------------------------------------------

global inline void rcc_pwr_enable (void)
{
	rcc_regs->rcc_apb1enr |= RCC_APB1ENR_PWREN_ON;
}

global void rcc_system_clk_config(bool hse_bypassed)
{
	//enable writings to pwr registers first
	rcc_pwr_enable();

	//configure the cr register based on whether hse is bypassed (crystal not used)
	//the hsi clock source is not yet disabled
	rcc_regs->rcc_cr |= hse_bypassed ? RCC_CR_HSE_BYPASSED : RCC_CR_HSE_CRYSTAL;

	//wait till HSE is ready and stable
	while(!(rcc_regs->rcc_cr & RCC_CR_HSERDY));

	//set up the pll configure register before proceeding
	rcc_regs->rcc_pllcfgr = RCC_PLLCFGR_SETUP;

	//enable pll
	rcc_regs->rcc_cr |= RCC_CR_PLLON_ON;

	//enable over-drive in power registers
	pwr_regs->pwr_cr |=  (PWR_CR_ODEN_ON);

	//wait till  PWR_CSR_ODRDY bit cleared for switching
	while(!(pwr_regs->pwr_csr & PWR_CSR_ODRDY_ON));

	//set the over-drive switch
	pwr_regs->pwr_cr |=  PWR_CR_ODSWEN_ON;

	while(!(pwr_regs->pwr_csr & PWR_CSR_ODSWRDY_ON));

	//configure flash latency
	flash_regs->flash_acr = FLASH_ACR_LATENCY;

	//wait till PLL is locked
	while(!(rcc_regs->rcc_cr & RCC_CR_PLLRDY));


	//pull the clock switch to use pllclk as systemclk
	//set up the clock prescalers for ahb, apb1 and apb2
	//ahb1 runs at 180 MHz just as the system clock
	//apb1 runs at 45 MHz
	//ahb2 runs at 90 MHz
	rcc_regs->rcc_cfgr = RCC_CFGR_SETUP;


}

