add_executable(
    day1
    day1.c
    lib.c
    data.c
    ../libs/display.c
)

target_link_libraries(
    day1
    pico_stdlib
)

target_compile_definitions(
    day1
    PRIVATE
    DISPLAY_SHIFT_REGISTERS=1
)
