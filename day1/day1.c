#include "data.h"
#include "lib.h"
#include "libs/display.h"

int main(void){
    run(get_data(), get_size());

    while(1) {
        display(get_number_of_hits());
    }

    return 0;
}
