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
