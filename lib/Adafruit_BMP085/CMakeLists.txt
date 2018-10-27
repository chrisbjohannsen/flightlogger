# tell the build system what to build
add_library(adafruit-bmp085 Adafruit_BMP085.cpp )
# for libraries also add the directory to the include path
target_include_directories(adafruit-bmp085 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(adafruit-bmp085 arduino-core)