################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../SqlServer/MongoServer.cpp \
../SqlServer/RedisServer.cpp \
../SqlServer/RedisUtil.cpp 

OBJS += \
./SqlServer/MongoServer.o \
./SqlServer/RedisServer.o \
./SqlServer/RedisUtil.o 

CPP_DEPS += \
./SqlServer/MongoServer.d \
./SqlServer/RedisServer.d \
./SqlServer/RedisUtil.d 


# Each subdirectory must supply rules for building sources it contributes
SqlServer/%.o: ../SqlServer/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


