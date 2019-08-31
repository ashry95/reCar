################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD.c \
../dio.c \
../external_interrupt.c \
../icu_new.c \
../main.c \
../timer0.c \
../timer2.c 

OBJS += \
./LCD.o \
./dio.o \
./external_interrupt.o \
./icu_new.o \
./main.o \
./timer0.o \
./timer2.o 

C_DEPS += \
./LCD.d \
./dio.d \
./external_interrupt.d \
./icu_new.d \
./main.d \
./timer0.d \
./timer2.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


