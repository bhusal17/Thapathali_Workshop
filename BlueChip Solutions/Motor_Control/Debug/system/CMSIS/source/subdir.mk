################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../system/CMSIS/source/startup_stm32f103xb.S 

OBJS += \
./system/CMSIS/source/startup_stm32f103xb.o 

S_UPPER_DEPS += \
./system/CMSIS/source/startup_stm32f103xb.d 


# Each subdirectory must supply rules for building sources it contributes
system/CMSIS/source/%.o: ../system/CMSIS/source/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


