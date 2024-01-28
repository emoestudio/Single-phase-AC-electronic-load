################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/adc.c \
../Core/Src/dac.c \
../Core/Src/dma.c \
../Core/Src/eva_PI_control.c \
../Core/Src/eva_adc.c \
../Core/Src/eva_clock_timer.c \
../Core/Src/eva_driver.c \
../Core/Src/eva_key.c \
../Core/Src/eva_paremeters.c \
../Core/Src/eva_pid.c \
../Core/Src/eva_pll.c \
../Core/Src/eva_protect.c \
../Core/Src/eva_queue.c \
../Core/Src/eva_screen.c \
../Core/Src/eva_timer_exti.c \
../Core/Src/eva_value_set.c \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/tim.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/adc.o \
./Core/Src/dac.o \
./Core/Src/dma.o \
./Core/Src/eva_PI_control.o \
./Core/Src/eva_adc.o \
./Core/Src/eva_clock_timer.o \
./Core/Src/eva_driver.o \
./Core/Src/eva_key.o \
./Core/Src/eva_paremeters.o \
./Core/Src/eva_pid.o \
./Core/Src/eva_pll.o \
./Core/Src/eva_protect.o \
./Core/Src/eva_queue.o \
./Core/Src/eva_screen.o \
./Core/Src/eva_timer_exti.o \
./Core/Src/eva_value_set.o \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/tim.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/adc.d \
./Core/Src/dac.d \
./Core/Src/dma.d \
./Core/Src/eva_PI_control.d \
./Core/Src/eva_adc.d \
./Core/Src/eva_clock_timer.d \
./Core/Src/eva_driver.d \
./Core/Src/eva_key.d \
./Core/Src/eva_paremeters.d \
./Core/Src/eva_pid.d \
./Core/Src/eva_pll.d \
./Core/Src/eva_protect.d \
./Core/Src/eva_queue.d \
./Core/Src/eva_screen.d \
./Core/Src/eva_timer_exti.d \
./Core/Src/eva_value_set.d \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/tim.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -D__FPU_PRESENT -D__FPU_PRESENT -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/ARM/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/adc.d ./Core/Src/adc.o ./Core/Src/adc.su ./Core/Src/dac.d ./Core/Src/dac.o ./Core/Src/dac.su ./Core/Src/dma.d ./Core/Src/dma.o ./Core/Src/dma.su ./Core/Src/eva_PI_control.d ./Core/Src/eva_PI_control.o ./Core/Src/eva_PI_control.su ./Core/Src/eva_adc.d ./Core/Src/eva_adc.o ./Core/Src/eva_adc.su ./Core/Src/eva_clock_timer.d ./Core/Src/eva_clock_timer.o ./Core/Src/eva_clock_timer.su ./Core/Src/eva_driver.d ./Core/Src/eva_driver.o ./Core/Src/eva_driver.su ./Core/Src/eva_key.d ./Core/Src/eva_key.o ./Core/Src/eva_key.su ./Core/Src/eva_paremeters.d ./Core/Src/eva_paremeters.o ./Core/Src/eva_paremeters.su ./Core/Src/eva_pid.d ./Core/Src/eva_pid.o ./Core/Src/eva_pid.su ./Core/Src/eva_pll.d ./Core/Src/eva_pll.o ./Core/Src/eva_pll.su ./Core/Src/eva_protect.d ./Core/Src/eva_protect.o ./Core/Src/eva_protect.su ./Core/Src/eva_queue.d ./Core/Src/eva_queue.o ./Core/Src/eva_queue.su ./Core/Src/eva_screen.d ./Core/Src/eva_screen.o ./Core/Src/eva_screen.su ./Core/Src/eva_timer_exti.d ./Core/Src/eva_timer_exti.o ./Core/Src/eva_timer_exti.su ./Core/Src/eva_value_set.d ./Core/Src/eva_value_set.o ./Core/Src/eva_value_set.su ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src

