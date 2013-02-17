################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../RpcServer/Request.cpp \
../RpcServer/Response.cpp \
../RpcServer/Server.cpp 

OBJS += \
./RpcServer/Request.o \
./RpcServer/Response.o \
./RpcServer/Server.o 

CPP_DEPS += \
./RpcServer/Request.d \
./RpcServer/Response.d \
./RpcServer/Server.d 


# Each subdirectory must supply rules for building sources it contributes
RpcServer/%.o: ../RpcServer/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


