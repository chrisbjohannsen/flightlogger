# tell the build system what to build
add_library(adafruit-gps Adafruit_GPS.cpp )

# for libraries also add the directory to the include path
target_include_directories(adafruit-gps PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(adafruit-gps arduino-core SoftwareSerial)