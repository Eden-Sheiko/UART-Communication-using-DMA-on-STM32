################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTG/Src/RTG.c \
../RTG/Src/Tools.c 

OBJS += \
./RTG/Src/RTG.o \
./RTG/Src/Tools.o 

C_DEPS += \
./RTG/Src/RTG.d \
./RTG/Src/Tools.d 


# Each subdirectory must supply rules for building sources it contributes
RTG/Src/%.o RTG/Src/%.su: ../RTG/Src/%.c RTG/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I"C:/Users/edens/Downloads/F7_UART_WithDMA-20230516T143620Z-001/F7_UART_WithDMA/RTG/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-RTG-2f-Src

clean-RTG-2f-Src:
	-$(RM) ./RTG/Src/RTG.d ./RTG/Src/RTG.o ./RTG/Src/RTG.su ./RTG/Src/Tools.d ./RTG/Src/Tools.o ./RTG/Src/Tools.su

.PHONY: clean-RTG-2f-Src

