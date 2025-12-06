#include <stdbool.h>

#include "pico/stdlib.h"
#include "pico/binary_info.h"

#include "../../libs/display.h"

int main(void){
    while(1){
        display(0x8888444422221111);
        sleep_ms(2000);
    }

    return 0;
}
