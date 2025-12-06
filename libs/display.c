#include <stdint.h>
#include <stdbool.h>

#include "pico/stdlib.h"
#include "pico/binary_info.h"

#ifndef SERIAL_DISPLAY_PIN
    #define SERIAL_DISPLAY_PIN 19 // Data pin for the display
#endif // SERIAL_DISPLAY_PIN

#ifndef SERIAL_DISPLAY_CLOCK_PIN
    #define SERIAL_DISPLAY_CLOCK_PIN 18 
#endif // SERIAL_DISPLAY_CLOCK_PIN

#ifndef SERIAL_DISPLAY_WORD_BUTTON_PIN
    #define SERIAL_DISPLAY_WORD_BUTTON_PIN 28
#endif // SERIAL_DISPLAY_WORD_BUTTON_PIN

#ifndef DISPLAY_RESET_PIN
    #define DISPLAY_RESET_PIN 20
#endif

#define DISPLAY_WORD_INDICATOR_PIN_0 27
#define DISPLAY_WORD_INDICATOR_PIN_1 26
#define DISPLAY_WORD_INDICATOR_PIN_2 22
#define DISPLAY_WORD_INDICATOR_PIN_3 21

#define DISPLAY_SHIFT_REGISTER_MASK 0x0001

#define CLOCK_ON  1
#define CLOCK_OFF 0

#define DISPLAY_SLEEP 5 //ms

#define ARRAY_SIZE(array) sizeof(array) / sizeof(array[0])

// gpio_init(LED_PIN);
// gpio_set_dir(LED_PIN, GPIO_OUT);
// gpio_put(LED_PIN, 1);

static bool display_inited = false;

static uint64_t masks[] = {
    0x000000000000ffff,
    0x00000000ffff0000,
    0x0000ffff00000000,
    0xffff000000000000,
};

static uint8_t inidcator_leds[] = {
  DISPLAY_WORD_INDICATOR_PIN_0,  
  DISPLAY_WORD_INDICATOR_PIN_1,  
  DISPLAY_WORD_INDICATOR_PIN_2,  
  DISPLAY_WORD_INDICATOR_PIN_3,  
};

static void reset_indicator_pins(){
    for (uint8_t pin = 0; pin < ARRAY_SIZE(inidcator_leds); pin++){
        gpio_put(inidcator_leds[pin], CLOCK_OFF);
    }
    sleep_ms(5);
}

static void set_inidicator_pin(uint8_t pin) {
    reset_indicator_pins();
    gpio_put(inidcator_leds[pin], CLOCK_ON);
    sleep_ms(5);
}
static void display_reset(){
    gpio_put(DISPLAY_RESET_PIN, CLOCK_OFF);
    sleep_ms(10);
    gpio_put(DISPLAY_RESET_PIN, CLOCK_ON);
    sleep_ms(10);
}

static void display_init() {
    if (!display_inited) {
        gpio_init(SERIAL_DISPLAY_PIN);
        gpio_set_dir(SERIAL_DISPLAY_PIN, GPIO_OUT);
        gpio_put(SERIAL_DISPLAY_PIN, CLOCK_OFF);

        gpio_init(DISPLAY_RESET_PIN);
        gpio_set_dir(DISPLAY_RESET_PIN, GPIO_OUT);
        gpio_put(DISPLAY_RESET_PIN, CLOCK_ON); // !CLR

        gpio_init(SERIAL_DISPLAY_WORD_BUTTON_PIN);
        gpio_set_dir(SERIAL_DISPLAY_WORD_BUTTON_PIN, GPIO_IN);
#ifdef DISPLAY_SHIFT_REGISTERS
        gpio_init(SERIAL_DISPLAY_CLOCK_PIN);
        gpio_set_dir(SERIAL_DISPLAY_CLOCK_PIN, GPIO_OUT);
        gpio_put(SERIAL_DISPLAY_CLOCK_PIN, CLOCK_OFF);
        gpio_init(SERIAL_DISPLAY_WORD_BUTTON_PIN);
        gpio_set_dir(SERIAL_DISPLAY_WORD_BUTTON_PIN, GPIO_IN);
#endif // DISPLAY_SHIFT_REGISTERS

        for (uint8_t pin = 0; pin < ARRAY_SIZE(inidcator_leds); pin++){
            gpio_init(inidcator_leds[pin]);
            gpio_set_dir(inidcator_leds[pin], GPIO_OUT);
        }

        reset_indicator_pins();
        display_reset();
        display_inited = true;
    }
}

static void wait_for_button_press(){
    while (1) {
        if (gpio_get(SERIAL_DISPLAY_WORD_BUTTON_PIN)){
            sleep_ms(1000);
            break;
        }
    }
    sleep_ms(1000);
}

void display_word(uint16_t word, bool reset_display) {
    display_init();

    if (reset_display) {
        display_reset();
    }

#ifdef DISPLAY_4_BIT_ADDERS
    for (uint16_t counter = 0; counter < word; counter++) {
        gpio_put(SERIAL_DISPLAY_PIN, CLOCK_OFF);
        sleep_ms(10);
        gpio_put(SERIAL_DISPLAY_PIN, CLOCK_ON);
        sleep_ms(10);
    }
#elifdef DISPLAY_SHIFT_REGISTERS // DISPLAY_4_BIT_ADDERS
    sleep_ms(DISPLAY_SLEEP);
    gpio_put(SERIAL_DISPLAY_CLOCK_PIN, CLOCK_ON);
    sleep_ms(SERIAL_DISPLAY_CLOCK_PIN);
    gpio_put(SERIAL_DISPLAY_CLOCK_PIN, CLOCK_OFF);
    sleep_ms(SERIAL_DISPLAY_CLOCK_PIN);
    for (int8_t shift_counter = 15; shift_counter >= 0; shift_counter--){
        uint16_t tmp_word = (word >> shift_counter) & DISPLAY_SHIFT_REGISTER_MASK;
        if (tmp_word == 1) {
            gpio_put(SERIAL_DISPLAY_PIN, CLOCK_ON);
        } else {
            gpio_put(SERIAL_DISPLAY_PIN, CLOCK_OFF);
        }
        sleep_ms(SERIAL_DISPLAY_CLOCK_PIN);
        gpio_put(SERIAL_DISPLAY_CLOCK_PIN, CLOCK_ON);
        sleep_ms(SERIAL_DISPLAY_CLOCK_PIN);
        gpio_put(SERIAL_DISPLAY_CLOCK_PIN, CLOCK_OFF);
    } 
#endif
}

void display(uint64_t value) {
    display_init();

    uint8_t shift = 0;
    uint16_t word = 0;

    for (uint8_t i = 0; i < ARRAY_SIZE(masks); i++) {
        set_inidicator_pin(i);
        word = (masks[i] & value) >> shift;
        shift += 16;
        display_word(word, true);
        wait_for_button_press();
        sleep_ms(100);
    }
}
