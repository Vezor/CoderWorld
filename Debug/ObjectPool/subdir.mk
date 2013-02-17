################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ObjectPool/PoolObject.cpp 

OBJS += \
./ObjectPool/PoolObject.o 

CPP_DEPS += \
./ObjectPool/PoolObject.d 


# Each subdirectory must supply rules for building sources it contributes
ObjectPool/%.o: ../ObjectPool/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


