################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Ants.cpp \
../src/Board.cpp \
../src/Doodlebugs.cpp \
../src/Organism.cpp \
../src/PA5.cpp 

OBJS += \
./src/Ants.o \
./src/Board.o \
./src/Doodlebugs.o \
./src/Organism.o \
./src/PA5.o 

CPP_DEPS += \
./src/Ants.d \
./src/Board.d \
./src/Doodlebugs.d \
./src/Organism.d \
./src/PA5.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


