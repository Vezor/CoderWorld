################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ProgramRunner/cpprunner.cpp \
../ProgramRunner/crunner.cpp \
../ProgramRunner/csharprunner.cpp \
../ProgramRunner/javarunner.cpp \
../ProgramRunner/pyrunner.cpp 

OBJS += \
./ProgramRunner/cpprunner.o \
./ProgramRunner/crunner.o \
./ProgramRunner/csharprunner.o \
./ProgramRunner/javarunner.o \
./ProgramRunner/pyrunner.o 

CPP_DEPS += \
./ProgramRunner/cpprunner.d \
./ProgramRunner/crunner.d \
./ProgramRunner/csharprunner.d \
./ProgramRunner/javarunner.d \
./ProgramRunner/pyrunner.d 


# Each subdirectory must supply rules for building sources it contributes
ProgramRunner/%.o: ../ProgramRunner/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


