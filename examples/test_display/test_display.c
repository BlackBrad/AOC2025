#include <stdbool.h>

#include "pico/stdlib.h"
#include "pico/binary_info.h"

#include "../../libs/display.h"

int main(void){
    while(1){
        gpio_put(13, 1);
        sleep_ms(500);
        gpio_put(13, 0);
        sleep_ms(500);
        display_word(0x0088, true);
        sleep_ms(2000);
        display_word(0x00aa, true);
        sleep_ms(2000);
        display_word(0x0055, true);
        sleep_ms(2000);
        display_word(0x0066, true);
        sleep_ms(2000);
        display_word(0x0077, true);
        sleep_ms(2000);
        display_word(0x00ff, true);
        sleep_ms(2000);
        display_word(0x1111, true);
        sleep_ms(2000);
        display_word(0x6666, true);
        sleep_ms(2000);
        display_word(0xffff, true);
        sleep_ms(2000);
    }

    return 0;
}
