cmake_minimum_required(VERSION 3.12)

#Import pico-sdk librairie
set(FETCHCONTENT_QUIET FALSE)
set(PICO_SDK_FETCH_FROM_GIT ON)
set(PICO_SDK_FETCH_FROM_GIT_PATH ${CMAKE_CURRENT_LIST_DIR}/pico-sdk)
set(PICO_TOOLCHAIN_PATH "${PICO_TOOLCHAIN_PATH}" CACHE INTERNAL "")

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)
project(serial C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

#set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()


# Add hello world example
add_subdirectory(src)


