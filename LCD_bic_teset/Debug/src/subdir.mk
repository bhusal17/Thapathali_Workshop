################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/api_keypad_driver.c \
../src/api_lcd_driver.c \
../src/gpio_interface.c \
../src/main.c \
../src/stm32f1xx_hal_msp.c \
../src/stm32f1xx_it.c 

OBJS += \
./src/api_keypad_driver.o \
./src/api_lcd_driver.o \
./src/gpio_interface.o \
./src/main.o \
./src/stm32f1xx_hal_msp.o \
./src/stm32f1xx_it.o 

C_DEPS += \
./src/api_keypad_driver.d \
./src/api_lcd_driver.d \
./src/gpio_interface.d \
./src/main.d \
./src/stm32f1xx_hal_msp.d \
./src/stm32f1xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DTRACE -DSTM32F103xB -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1xx" -I"../system/include/cmsis/device" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


