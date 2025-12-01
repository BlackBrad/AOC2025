add_executable(
    blink
    blink_led.c
)

add_executable(
    blink_count
    blink_led_count.c
)

pico_add_extra_outputs(blink)
pico_add_extra_outputs(blink_count)

target_link_libraries(
    blink
    pico_stdlib
)

target_link_libraries(
    blink
    pico_stdlib
)

target_link_libraries(
    blink_count
    pico_stdlib
)
