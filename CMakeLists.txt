#=====================================================================================
cmake_minimum_required(VERSION 3.0)

macro(print_all_variables)
    message(STATUS "print_all_variables------------------------------------------{")
    get_cmake_property(_variableNames VARIABLES)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
    message(STATUS "print_all_variables------------------------------------------}")
endmacro()

# the toolchain file
set(CMAKE_TOOLCHAIN_FILE /Users/chris/Development/avr-arduino-cmake/avr-arduino-toolchain.cmake)

# if you want to compile Arduino sketches, set this to the Arduino SDK dir (1.6.5)
set(ARDUINO_SDK_PATH "lib/ArduinoCore-avr" CACHE STRING "Arduino SDK Path")

# project name and code types we use
project (flightlogger C CXX ASM)

# necessary settings for the chip we use
set(MCU         atmega328p)
set(F_CPU       16000000)
set(BAUD        115200)

# set the programmer and the device to use (arduino, usbasp, ...)
set(PROGRAMMER  arduino)
set(SERIAL_DEV  /dev/cu.SLAB_USBtoUART)

# only needed if we do floating point math and want to print floats with printf
#set(EXTRA_LIBS "-lm -lprintf_flt")

# build arduino libs
# setup_arduino_core()

# adding static libs (a directory that contains subdirs with libs)
add_libraries(lib)

# adding the normal avr targets (a directory contains subdirs with targets)
add_sources(src)

print_all_variables()

# add the sketches directory (contains sketch directories)
#add_sketches(sketches)
add_executable(flightlogger src/FL2.cpp)

target_link_libraries(flightlogger arduino-core SoftwareSerial Wire)

