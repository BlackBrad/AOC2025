#include <stdint.h>
#include <stdbool.h>

#include "pico/stdlib.h"
#include "pico/binary_info.h"

#define SERIAL_DISPLAY_PIN 6
#define DISPLAY_RESET_PIN  7
#define CLOCK_ON  1
#define CLOCK_OFF 0
#define ARRAY_SIZE(array) sizeof(array) / sizeof(array[0])

// gpio_init(LED_PIN);
// gpio_set_dir(LED_PIN, GPIO_OUT);
// gpio_put(LED_PIN, 1);

static bool display_inited = false;

static uint64_t masks[] = {
    0x000000ff,
    0x0000ff00,
    0x00ff0000,
    0xff000000,
};

static void display_reset(){
    gpio_put(DISPLAY_RESET_PIN, CLOCK_ON);
    sleep_ms(75);
    gpio_put(DISPLAY_RESET_PIN, CLOCK_OFF);
    sleep_ms(75);
    gpio_put(DISPLAY_RESET_PIN, CLOCK_ON);
    sleep_ms(75);
}

static void display_init() {
    if (!display_inited) {
        gpio_init(SERIAL_DISPLAY_PIN);
        gpio_set_dir(SERIAL_DISPLAY_PIN, GPIO_OUT);
        gpio_init(DISPLAY_RESET_PIN);
        gpio_set_dir(DISPLAY_RESET_PIN, GPIO_OUT);
        gpio_put(DISPLAY_RESET_PIN, CLOCK_ON);
        display_reset();
        display_inited = true;
    }
}

void display_word(uint16_t word, bool reset_display) {
    display_init();
    if (reset_display) {
        display_reset();
    }

    for (uint16_t counter = 0; counter < word; counter++) {
        gpio_put(SERIAL_DISPLAY_PIN, CLOCK_OFF);
        sleep_ms(10);
        gpio_put(SERIAL_DISPLAY_PIN, CLOCK_ON);
        sleep_ms(10);
    } 
}

void display(uint64_t value) {
    display_init();

    uint8_t shift = 0;
    uint16_t word = 0;

    for (uint8_t i = 0; i < ARRAY_SIZE(masks); i++) {
        word = (masks[i] & value) >> shift;
        shift += 16;
        display_word(word, true);
    }
}
