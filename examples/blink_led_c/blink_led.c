#include "pico/stdlib.h"
#include "pico/binary_info.h"

const uint LED_PIN = 18;

int main(void){

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while(1){
        gpio_put(LED_PIN, 1);
    }

    return 0;
}
