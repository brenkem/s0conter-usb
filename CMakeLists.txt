cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_FETCH_FROM_GIT on)
include(pico_sdk_import.cmake)

project(boitus_usb C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(boitus_usb boitus_usb.c)

pico_enable_stdio_usb(boitus_usb 1)
pico_enable_stdio_uart(boitus_usb 0)

pico_add_extra_outputs(boitus_usb)

target_link_libraries(boitus_usb pico_stdlib)
