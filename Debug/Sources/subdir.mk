################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/CircBuf.c \
../Sources/conversion.c \
../Sources/main.c \
../Sources/memory.c \
../Sources/project2.c \
../Sources/uart.c 

OBJS += \
./Sources/CircBuf.o \
./Sources/conversion.o \
./Sources/main.o \
./Sources/memory.o \
./Sources/project2.o \
./Sources/uart.o 

C_DEPS += \
./Sources/CircBuf.d \
./Sources/conversion.d \
./Sources/main.d \
./Sources/memory.d \
./Sources/project2.d \
./Sources/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MKL25Z128VLK4" -I"../Sources" -I"../Project_Settings/Startup_Code" -I"../SDK/platform/CMSIS/Include" -I"../SDK/platform/devices" -I"../SDK/platform/devices/MKL25Z4/include" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


