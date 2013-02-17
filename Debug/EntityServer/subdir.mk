################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../EntityServer/HugeEntityServer.cpp \
../EntityServer/IDGenerator.cpp \
../EntityServer/ListLinkEntityServer.cpp \
../EntityServer/SetLinkEntityServer.cpp \
../EntityServer/SocialEntityServer.cpp 

OBJS += \
./EntityServer/HugeEntityServer.o \
./EntityServer/IDGenerator.o \
./EntityServer/ListLinkEntityServer.o \
./EntityServer/SetLinkEntityServer.o \
./EntityServer/SocialEntityServer.o 

CPP_DEPS += \
./EntityServer/HugeEntityServer.d \
./EntityServer/IDGenerator.d \
./EntityServer/ListLinkEntityServer.d \
./EntityServer/SetLinkEntityServer.d \
./EntityServer/SocialEntityServer.d 


# Each subdirectory must supply rules for building sources it contributes
EntityServer/%.o: ../EntityServer/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


