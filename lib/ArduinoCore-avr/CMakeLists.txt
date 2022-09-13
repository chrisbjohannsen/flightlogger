message("Starting Arduino Lib Setup")
# set the paths
set(ARDUINO_CORES_PATH ${ARDUINO_SDK_PATH}/cores/arduino CACHE STRING "")
set(ARDUINO_VARIANTS_PATH ${ARDUINO_SDK_PATH}/variants/standard CACHE STRING "")
set(ARDUINO_LIBRARIES_PATH ${ARDUINO_SDK_PATH}/libraries CACHE STRING "")

# find arduino-core sources
set(CORE_SOURCES cores/arduino/Arduino.h
        cores/arduino/binary.h
        cores/arduino/Client.h
        cores/arduino/HardwareSerial.h
        cores/arduino/HardwareSerial_private.h
        cores/arduino/IPAddress.h
        cores/arduino/new.h
        cores/arduino/PluggableUSB.h
        cores/arduino/Print.h
        cores/arduino/Printable.h
        cores/arduino/Server.h
        cores/arduino/Stream.h
        cores/arduino/Udp.h
        cores/arduino/USBAPI.h
        cores/arduino/USBCore.h
        cores/arduino/USBDesc.h
        cores/arduino/WCharacter.h
        cores/arduino/wiring_private.h
        cores/arduino/wiring_pulse.S
        cores/arduino/WString.h)

set(ARDUINO_CORE_SRCS ${CORE_SOURCES} CACHE STRING "Arduino core library sources")
add_library(arduino_core ARDUINO_CORE_SRCS)
# setup the main arduino core target
target_include_directories(arduino-core PUBLIC ${ARDUINO_CORES_PATH})
target_include_directories(arduino-core PUBLIC ${ARDUINO_VARIANTS_PATH})