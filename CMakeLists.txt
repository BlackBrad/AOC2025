cmake_minimum_required(VERSION 3.12)

SET(BUILD_UNIT_TESTS FALSE CACHE STRING "Build unit tests rather than the executabe")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if (BUILD_UNIT_TESTS)
    project(aoc2025)
    add_subdirectory(Unity)
    add_subdirectory(tests)
else()
    set(PICO_BOARD "pico2")
    set(PICO_NO_PICOTOOL 1)
    set(PICO_PLATFORM "rp2350-riscv")
    set(PICO_GCC_TRIPLE "riscv32-unknown-elf")
    set(PICO_TOOLCHAIN_PATH "/opt/riscv/gcc14-rp2350-no-zcmp/bin/")
    set(PICO_SDK_PATH "/home/bradley/AOC2025/pico-sdk/")


    include(pico_sdk_import.cmake)

    project(aoc2025)

    pico_sdk_init()

    add_subdirectory(examples)
    add_subdirectory(day1)
endif()
