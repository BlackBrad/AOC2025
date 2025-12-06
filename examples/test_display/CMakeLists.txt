add_executable(
    test_display
    test_display.c
    ../../libs/display.c
)

pico_add_extra_outputs(test_display)

target_link_libraries(
    test_display
    pico_stdlib
)

target_compile_definitions(
    test_display
    PRIVATE
    DISPLAY_SHIFT_REGISTERS=1
)

add_executable(
    test_display_64
    test_display_64_bit.c
    ../../libs/display.c
)

pico_add_extra_outputs(test_display_64)

target_link_libraries(
    test_display_64
    pico_stdlib
)

target_compile_definitions(
    test_display_64
    PRIVATE
    DISPLAY_SHIFT_REGISTERS=1
)
