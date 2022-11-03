################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include COTS/MCAL/GIE/subdir.mk
-include COTS/MCAL/DIO/subdir.mk
-include COTS/HAL/LCD/subdir.mk
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
Final-AVR-Proj.lss \

FLASH_IMAGE += \
Final-AVR-Proj.hex \

EEPROM_IMAGE += \
Final-AVR-Proj.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Final-AVR-Proj.elf secondary-outputs

# Tool invocations
Final-AVR-Proj.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Final-AVR-Proj.map -mmcu=atmega32 -o "Final-AVR-Proj.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Final-AVR-Proj.lss: Final-AVR-Proj.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Final-AVR-Proj.elf  >"Final-AVR-Proj.lss"
	@echo 'Finished building: $@'
	@echo ' '

Final-AVR-Proj.hex: Final-AVR-Proj.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Final-AVR-Proj.elf  "Final-AVR-Proj.hex"
	@echo 'Finished building: $@'
	@echo ' '

Final-AVR-Proj.eep: Final-AVR-Proj.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Final-AVR-Proj.elf  "Final-AVR-Proj.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Final-AVR-Proj.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Final-AVR-Proj.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Final-AVR-Proj.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
