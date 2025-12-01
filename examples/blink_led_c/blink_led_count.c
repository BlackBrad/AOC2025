#include "pico/stdlib.h"
#include "pico/binary_info.h"

#include <stdint.h>

void reset_all_leds(){
    for (int i = 2; i < 6; i++){
        gpio_put(i, 0);
    }
}

int main(void){
    for (int i = 2; i < 6; i++){
        gpio_init(i);
        gpio_set_dir(i, GPIO_OUT);
    }

    while(1){
        for (uint8_t counter = 0; counter < 16; counter++) {
            if (counter & 0x01)
                gpio_put(5, 1);
            if (counter & 0x02)
                gpio_put(4, 1);
            if (counter & 0x04)
                gpio_put(3, 1);
            if (counter & 0x08)
                gpio_put(2, 1);
            sleep_ms(250);
            reset_all_leds();
        }

        for (int i = 0; i < 10; i++) {
            for (int i = 2; i < 6; i++) {
                gpio_put(i, 1);
                sleep_ms(150);
                reset_all_leds();
                sleep_ms(150);
            }
        }
        for (int i = 0; i < 20; i++) {
            for (int i = 2; i < 6; i++) {
                gpio_put(i, 1);
            }
            sleep_ms(50);
            reset_all_leds();
            sleep_ms(50);
        }
    }

    return 0;
}
