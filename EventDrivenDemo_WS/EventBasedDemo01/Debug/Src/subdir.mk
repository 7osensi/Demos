################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Stm32F103_ADC.c \
../Src/Stm32F103_AFIO.c \
../Src/Stm32F103_EXTI.c \
../Src/Stm32F103_GPIO.c \
../Src/Stm32F103_NVIC.c \
../Src/Stm32F103_RCC.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/Stm32F103_ADC.o \
./Src/Stm32F103_AFIO.o \
./Src/Stm32F103_EXTI.o \
./Src/Stm32F103_GPIO.o \
./Src/Stm32F103_NVIC.o \
./Src/Stm32F103_RCC.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/Stm32F103_ADC.d \
./Src/Stm32F103_AFIO.d \
./Src/Stm32F103_EXTI.d \
./Src/Stm32F103_GPIO.d \
./Src/Stm32F103_NVIC.d \
./Src/Stm32F103_RCC.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/Stm32F103_ADC.cyclo ./Src/Stm32F103_ADC.d ./Src/Stm32F103_ADC.o ./Src/Stm32F103_ADC.su ./Src/Stm32F103_AFIO.cyclo ./Src/Stm32F103_AFIO.d ./Src/Stm32F103_AFIO.o ./Src/Stm32F103_AFIO.su ./Src/Stm32F103_EXTI.cyclo ./Src/Stm32F103_EXTI.d ./Src/Stm32F103_EXTI.o ./Src/Stm32F103_EXTI.su ./Src/Stm32F103_GPIO.cyclo ./Src/Stm32F103_GPIO.d ./Src/Stm32F103_GPIO.o ./Src/Stm32F103_GPIO.su ./Src/Stm32F103_NVIC.cyclo ./Src/Stm32F103_NVIC.d ./Src/Stm32F103_NVIC.o ./Src/Stm32F103_NVIC.su ./Src/Stm32F103_RCC.cyclo ./Src/Stm32F103_RCC.d ./Src/Stm32F103_RCC.o ./Src/Stm32F103_RCC.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src
