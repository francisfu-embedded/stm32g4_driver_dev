################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/msys.c \
../Src/msys_test_main.c 

OBJS += \
./Src/msys.o \
./Src/msys_test_main.o 

C_DEPS += \
./Src/msys.d \
./Src/msys_test_main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/msys.o: ../Src/msys.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G4 -DNUCLEO_G431RB -DDEBUG -DSTM32G431RBTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/msys.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/msys_test_main.o: ../Src/msys_test_main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G4 -DNUCLEO_G431RB -DDEBUG -DSTM32G431RBTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/msys_test_main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

