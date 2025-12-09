#include "data.h"
#include "lib.h"
#include "libs/display.h"

int main(void){
    run_part2(get_data(), get_size());

    while(1) {
        display(0);
    }

    return 0;
}
