################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HCSR04/hcsr04.c 

OBJS += \
./HCSR04/hcsr04.o 

C_DEPS += \
./HCSR04/hcsr04.d 


# Each subdirectory must supply rules for building sources it contributes
HCSR04/hcsr04.o: ../HCSR04/hcsr04.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DUSE_FULL_LL_DRIVER -DDEBUG -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HCSR04/hcsr04.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

