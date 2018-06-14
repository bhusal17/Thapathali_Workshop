################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include system/CMSIS/source/subdir.mk
-include source/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
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
SECONDARY_FLASH += \
BluePill_GPIO_Interface.hex \

SECONDARY_SIZE += \
BluePill_GPIO_Interface.siz \


# All Target
all: BluePill_GPIO_Interface.elf secondary-outputs

# Tool invocations
BluePill_GPIO_Interface.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM Cross C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -T "/media/bhusal/Study/Learning/Embedded System/Embedded System Programming/Level-II 32 bit controller, Device driver and RTOS/STM32/STM32 Eclipse Linux/Thapathali_ARM_workshop/Thapathali_Workshop/BlueChip Solutions/BluePill_GPIO_Interface/ldscripts/STM32F103C8Tx_FLASH.ld" -Xlinker --gc-sections -Wl,-Map,"BluePill_GPIO_Interface.map" -o "BluePill_GPIO_Interface.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

BluePill_GPIO_Interface.hex: BluePill_GPIO_Interface.elf
	@echo 'Invoking: GNU ARM Cross Create Flash Image'
	arm-none-eabi-objcopy -O ihex "BluePill_GPIO_Interface.elf"  "BluePill_GPIO_Interface.hex"
	@echo 'Finished building: $@'
	@echo ' '

BluePill_GPIO_Interface.siz: BluePill_GPIO_Interface.elf
	@echo 'Invoking: GNU ARM Cross Print Size'
	arm-none-eabi-size --format=berkeley "BluePill_GPIO_Interface.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) BluePill_GPIO_Interface.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
