################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Compiler/BaseCompiler.cpp \
../Compiler/CCompiler.cpp \
../Compiler/CppCompiler.cpp \
../Compiler/JavaCompiler.cpp \
../Compiler/PyCompiler.cpp 

OBJS += \
./Compiler/BaseCompiler.o \
./Compiler/CCompiler.o \
./Compiler/CppCompiler.o \
./Compiler/JavaCompiler.o \
./Compiler/PyCompiler.o 

CPP_DEPS += \
./Compiler/BaseCompiler.d \
./Compiler/CCompiler.d \
./Compiler/CppCompiler.d \
./Compiler/JavaCompiler.d \
./Compiler/PyCompiler.d 


# Each subdirectory must supply rules for building sources it contributes
Compiler/%.o: ../Compiler/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


