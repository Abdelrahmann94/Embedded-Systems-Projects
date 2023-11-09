################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/Source/subdir.mk
-include MCAL/SPI/Source/subdir.mk
-include MCAL/PORT/SOURCE/subdir.mk
-include MCAL/I2C/SOURCE/subdir.mk
-include MCAL/DIO/SOURCE/subdir.mk
-include HAL/LCD/SOURCE/subdir.mk
-include HAL/KEYPAD/SOURCE/subdir.mk
-include HAL/EEPROM/SOURCE/subdir.mk
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
MASTER_PROJECT.lss \

FLASH_IMAGE += \
MASTER_PROJECT.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: MASTER_PROJECT.elf secondary-outputs

# Tool invocations
MASTER_PROJECT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,MASTER_PROJECT.map -mmcu=atmega32 -o "MASTER_PROJECT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

MASTER_PROJECT.lss: MASTER_PROJECT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S MASTER_PROJECT.elf  >"MASTER_PROJECT.lss"
	@echo 'Finished building: $@'
	@echo ' '

MASTER_PROJECT.hex: MASTER_PROJECT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex MASTER_PROJECT.elf  "MASTER_PROJECT.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: MASTER_PROJECT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 MASTER_PROJECT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) MASTER_PROJECT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
