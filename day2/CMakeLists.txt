add_executable(
    day2
    day2.c
    lib.c
    data.c
    ../libs/display.c
)

target_link_libraries(
    day2
    pico_stdlib
)

target_compile_definitions(
    day2
    PRIVATE
    DISPLAY_SHIFT_REGISTERS=1
)

add_executable(
    day2-2
    day2-2.c
    lib.c
    data.c
    ../libs/display.c
)

target_link_libraries(
    day2-2
    pico_stdlib
)

target_compile_definitions(
    day2-2
    PRIVATE
    DISPLAY_SHIFT_REGISTERS=1
)
