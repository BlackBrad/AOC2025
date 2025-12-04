#include "pico/stdlib.h"
//#include "pico/binary_info.h"

void _start_brad();

int main() {
    gpio_init(25);
    //gpio_set_dir(LED_PIN, GPIO_OUT);

    _start_brad();
}
