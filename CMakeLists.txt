cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_FETCH_FROM_GIT on)
include(pico_sdk_import.cmake)

project(s0counter_usb C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(s0counter-usb s0counter-usb.c)

pico_enable_stdio_usb(s0counter-usb 1)
pico_enable_stdio_uart(s0counter-usb 0)

pico_add_extra_outputs(s0counter-usb)

target_link_libraries(s0counter-usb pico_stdlib)
