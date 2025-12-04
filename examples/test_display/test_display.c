#include <stdbool.h>

#include "pico/stdlib.h"
#include "pico/binary_info.h"

#include "../../libs/display.h"

int main(void){
    while(1){
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
    }

    return 0;
}
