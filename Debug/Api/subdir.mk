################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Api/Api.cpp \
../Api/GetProfileApi.cpp \
../Api/LoginApi.cpp \
../Api/RegisterApi.cpp \
../Api/UpdateProfileApi.cpp 

OBJS += \
./Api/Api.o \
./Api/GetProfileApi.o \
./Api/LoginApi.o \
./Api/RegisterApi.o \
./Api/UpdateProfileApi.o 

CPP_DEPS += \
./Api/Api.d \
./Api/GetProfileApi.d \
./Api/LoginApi.d \
./Api/RegisterApi.d \
./Api/UpdateProfileApi.d 


# Each subdirectory must supply rules for building sources it contributes
Api/%.o: ../Api/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


