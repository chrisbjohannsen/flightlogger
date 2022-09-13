# tell the build system what to build
add_library(adafruit-l3gd20u Adafruit_L3GD20_U.cpp)

# for libraries also add the directory to the include path
target_include_directories(adafruit-l3gd20u PUBLIC ..)

target_link_libraries(adafruit-l3gd20u arduino-core Wire)