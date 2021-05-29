//******************************************************************************
// stm32g4_mem_map.h
// Author: Yuqi Fu
// Description:
// A memory map for stm32g4's registers to be used in digital power projects
//
//*******************************************************************************

#ifndef STM32G4_MEM_MAP_H_
#define STM32G4_MEM_MAP_H_

#include "driver_keyword_defs.h"

//
//Base addresses of peripheral registers:
//the peripheral registers of the microcontroller starts at the address 0x4000_0000,
//and ends at 0x6000_0000. Please refer to the chart at page 83-86 of the reference
//manual. The base addresses of the peripherals shown below are organized from lower
//to higher addresses
//
#define			TIM2_BASE_ADDR			0x40000000
#define			TIM3_BASE_ADDR			0x40000400
#define			TIM4_BASE_ADDR			0x40000800
#define			TIM5_BASE_ADDR			0x40000C00
#define			TIM6_BASE_ADDR			0x40001000
#define			TIM7_BASE_ADDR			0x40001400
#define			CRS_BASE_ADDR			0x40002000
#define			TAMP_BASE_ADDR			0x40002400
#define			RTC_BASE_ADDR			0x40002800
#define			WWDG_BASE_ADDR			0x40002C00
#define			IWDG_BASE_ADDR			0x40003000
#define			SPI2_BASE_ADDR			0x40003800
#define			SPI3_BASE_ADDR			0x40003C00
#define			USART2_BASE_ADDR		0x40004400
#define			USART3_BASE_ADDR		0x40004800
#define			UART4_BASE_ADDR			0x40004C00
#define			UART5_BASE_ADDR		    0x40005000
#define			I2C1_BASE_ADDR		    0x40005400
#define			I2C2_BASE_ADDR		    0x40005800
#define			USBFS_BASE_ADDR		    0x40005C00
#define			FDCAN1_BASE_ADDR		0x40006400
#define			FDCAN2_BASE_ADDR		0x40006800
#define			FDCAN3_BASE_ADDR		0x40006C00
#define			PWR_BASE_ADDR		    0x40007000
#define         I2C3_BASE_ADDR          0x40007800
#define         LPTIM1_BASE_ADDR        0x40007C00
#define         LPUART1_BASE_ADDR       0x40008000
#define         I2C4_BASE_ADDR          0x40008400
#define         UCPD1_BASE_ADDR         0x4000A000

#define			SYSCFG_BASE_ADDR		0x40010000
#define			VREFBUF_BASE_ADDR		0x40010030
#define			COMP_BASE_ADDR			0x40010200
#define			OPAMP_BASE_ADDR			0x40010300
#define			EXTI_BASE_ADDR			0x40010400
#define			TIM1_BASE_ADDR			0x40012C00
#define			SPI1_BASE_ADDR			0x40013000
#define			TIM8_BASE_ADDR			0x40013400
#define			USART1_BASE_ADDR		0x40013800
#define			TIM15_BASE_ADDR			0x40014000
#define			TIM16_BASE_ADDR			0x40014400
#define			TIM17_BASE_ADDR			0x40014800
#define 		TIM20_BASE_ADDR			0x40015000
#define			SAI1_BASE_ADDR			0x40015400
#define			HRTIM_BASE_ADDR			0x40016800
#define			DMA1_BASE_ADDR			0x40020000
#define			DMA2_BASE_ADDR			0x40020400
#define			DMAMUX_BASE_ADDR		0x40020800
#define			CORDIC_BASE_ADDR		0x40020C00
#define			RCC_BASE_ADDR			0x40021000
#define			FMAC_BASE_ADDR			0x40021400
#define			FLASH_BASE_ADDR			0x40022000
#define			CRC_BASE_ADDR			0x40023000
#define			GPIOA_BASE_ADDR			0x48000000
#define			GPIOB_BASE_ADDR			0x48000400
#define			GPIOC_BASE_ADDR			0x48000800
#define			GPIOD_BASE_ADDR			0x48000C00
#define			GPIOE_BASE_ADDR			0x48001000
#define			GPIOF_BASE_ADDR			0x48001400
#define			GPIOG_BASE_ADDR			0x48001800

//ADC not sure, to be added
//#define			ADC1_BASE_ADDR
//#define			ADC2_BASE_ADDR

#define			DAC1_BASE_ADDR			0x50000800
#define			DAC2_BASE_ADDR			0x50000C00
#define			DAC3_BASE_ADDR			0x50001000
#define			DAC4_BASE_ADDR			0x50001400
#define			AES_BASE_ADDR			0x50060000
#define			RNG_BASE_ADDR			0x50060800
#define			FSMC_BASE_ADDR			0xA0000000
#define 		QDSPI_BASE_ADDR 		0xA0001000

//
//Register set structures: add to this section when new driver is finished
//The registers are grouped into structures. Each structure is mapped to a specific base address
//as defined above
//

//
//RCC Registers
//

typedef struct
{
	vo uint32 rcc_cr;
	vo uint32 rcc_icscr;
	vo uint32 rcc_cfgr;
	vo uint32 rcc_pllcfgr;
	vo uint32 rcc_rsvd0[2];

	vo uint32 rcc_cier;
	vo uint32 rcc_cifr;
	vo uint32 rcc_cicr;
	vo uint32 rcc_rsvd1;

	vo uint32 rcc_ahb1rstr;
	vo uint32 rcc_ahb2rstr;
	vo uint32 rcc_ahb3rstr;
	vo uint32 rcc_rsvd2;

	vo uint32 rcc_apb1rstr1;
	vo uint32 rcc_apb1rstr2;
	vo uint32 rcc_apb2rstr;
	vo uint32 rcc_rsvd3;

	vo uint32 rcc_ahb1enr;
	vo uint32 rcc_ahb2enr;
	vo uint32 rcc_ahb3enr;
	vo uint32 rcc_rsvd4;

	vo uint32 rcc_apb1enr1;
	vo uint32 rcc_apb1enr2;
	vo uint32 rcc_apb2enr;
	vo uint32 rcc_rsvd5;

	vo uint32 rcc_ahb1smenr;
	vo uint32 rcc_ahb2smenr;
	vo uint32 rcc_ahb3smenr;
	vo uint32 rcc_rsvd6;

	vo uint32 rcc_apb1smenr1;
	vo uint32 rcc_apb1smenr2;
	vo uint32 rcc_apb2smenr;
	vo uint32 rcc_rsvd7;

	vo uint32 rcc_ccipr;
	vo uint32 rcc_rsvd8;
	vo uint32 rcc_bdcr;
	vo uint32 rcc_csr;
	vo uint32 rcc_crrcr;
	vo uint32 rcc_ccipr2;
} rcc_reg_set;

//
//PWR Registers
//
typedef struct
{
	vo uint32 pwr_cr1;
	vo uint32 pwr_cr2;
	vo uint32 pwr_cr3;
	vo uint32 pwr_cr4;
	vo uint32 pwr_sr1;
	vo uint32 pwr_sr2;
	vo uint32 pwr_scr;
	vo uint32 pwr_rsvd0;
	vo uint32 pwr_pucra;
	vo uint32 pwr_pdcra;
	vo uint32 pwr_pucrb;
	vo uint32 pwr_pdcrb;
	vo uint32 pwr_pucrc;
	vo uint32 pwr_pdcrc;
	vo uint32 pwr_pucrd;
	vo uint32 pwr_pdcrd;
	vo uint32 pwr_pucre;
	vo uint32 pwr_pdcre;
	vo uint32 pwr_pucrf;
	vo uint32 pwr_pdcrf;
	vo uint32 pwr_pucrg;
	vo uint32 pwr_pdcrg;
	vo uint32 pwr_rsvd1[10];
	vo uint32 pwr_cr5;
} pwr_reg_set;

//
//FLSHI Registers:
//The G431 microcontroller is a category 2 device
//The register map is put as according to the rfm section 5
//

typedef struct
{
	vo uint32 flash_acr;
	vo uint32 flash_pdkeyr;
	vo uint32 flash_keyr;
	vo uint32 flash_optkeyr;
	vo uint32 flash_sr;
	vo uint32 flash_cr;
	vo uint32 flash_eccr;
	vo uint32 flash_rsvd0;
	vo uint32 flash_optr;
	vo uint32 flash_pcrop1sr;
	vo uint32 flash_pcrop1er;
	vo uint32 flash_wrp1ar;
	vo uint32 flash_wrp1br;
	vo uint32 flash_rsvd1[16];
	vo uint32 flash_sec1r;
} flash_reg_set;

#endif
