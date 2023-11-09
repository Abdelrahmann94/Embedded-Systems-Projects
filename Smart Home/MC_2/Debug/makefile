################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/Source/subdir.mk
-include MCAL/TIMER/Source/subdir.mk
-include MCAL/SPI/Source/subdir.mk
-include MCAL/PORT/Source/subdir.mk
-include MCAL/GIE/Source/subdir.mk
-include MCAL/EXTI/Source/subdir.mk
-include MCAL/DIO/Source/subdir.mk
-include MCAL/ADC/Source/subdir.mk
-include HAL/LCD/Source/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SLAVE_PROJECT.lss \

FLASH_IMAGE += \
SLAVE_PROJECT.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SLAVE_PROJECT.elf secondary-outputs

# Tool invocations
SLAVE_PROJECT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SLAVE_PROJECT.map -mmcu=atmega32 -o "SLAVE_PROJECT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SLAVE_PROJECT.lss: SLAVE_PROJECT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SLAVE_PROJECT.elf  >"SLAVE_PROJECT.lss"
	@echo 'Finished building: $@'
	@echo ' '

SLAVE_PROJECT.hex: SLAVE_PROJECT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SLAVE_PROJECT.elf  "SLAVE_PROJECT.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SLAVE_PROJECT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SLAVE_PROJECT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SLAVE_PROJECT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
