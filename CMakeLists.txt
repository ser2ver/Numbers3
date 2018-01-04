cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME Numbers3)
project(${PROJECT_NAME})

#set(${CMAKE_PROJECT_NAME}_SKETCH Numbers3.ino Settings.h)
set(${CMAKE_PROJECT_NAME}_HDRS Settings.h DisplayDigit.h DisplayNumber.h Display.h Termo.h Light.h)
set(${CMAKE_PROJECT_NAME}_SRCS Numbers3.ino DisplayDigit.cpp DisplayNumber.cpp Display.cpp Termo.cpp Light.cpp)

### Uncomment below additional settings as needed.
set(${CMAKE_PROJECT_NAME}_BOARD uno)
set(${CMAKE_PROJECT_NAME}_PORT /dev/ttyUSB0)
set(uno.upload.speed 9600)

generate_arduino_firmware(${CMAKE_PROJECT_NAME})
