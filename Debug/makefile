################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include HCSR04/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
ultrasonic.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ultrasonic.list \

OBJCOPY_HEX += \
ultrasonic.hex \

OBJCOPY_BIN += \
ultrasonic.bin \


# All Target
all: ultrasonic.elf secondary-outputs

# Tool invocations
ultrasonic.elf: $(OBJS) $(USER_OBJS) /Users/kennedyotieno/STM32CubeIDE/workspace_1.0.2/ultrasonic/STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "ultrasonic.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"/Users/kennedyotieno/STM32CubeIDE/workspace_1.0.2/ultrasonic/STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="ultrasonic.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ultrasonic.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ultrasonic.list"
	@echo 'Finished building: $@'
	@echo ' '

ultrasonic.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "ultrasonic.hex"
	@echo 'Finished building: $@'
	@echo ' '

ultrasonic.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "ultrasonic.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
