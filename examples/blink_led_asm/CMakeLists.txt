add_executable(
    blinkasm
    main.c
    just_enable.s
)

pico_add_extra_outputs(blinkasm)

target_link_libraries(
    blinkasm
    pico_stdlib
)

