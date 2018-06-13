################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/main.c \
../source/system_stm32f1xx.c 

OBJS += \
./source/main.o \
./source/system_stm32f1xx.o 

C_DEPS += \
./source/main.d \
./source/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/media/bhusal/Study/Learning/Embedded System/Embedded System Programming/Level-II 32 bit controller, Device driver and RTOS/STM32/STM32 Eclipse Linux/STM32F103xx BlueChip Projects/STM32F103xx BlueChip Template/stm32f103_bluePill_template/include" -I"/media/bhusal/Study/Learning/Embedded System/Embedded System Programming/Level-II 32 bit controller, Device driver and RTOS/STM32/STM32 Eclipse Linux/STM32F103xx BlueChip Projects/STM32F103xx BlueChip Template/stm32f103_bluePill_template/system/CMSIS/include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


