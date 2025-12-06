#include "lib.h"

static uint64_t number_of_hits = 0;
static uint64_t rotation = 50;

uint64_t get_rotation(){
    return rotation;
}

void get_rotation_and_number(char *str, bool *direction, uint64_t *rotation_count){
}

void count_rotation(char *str){
    bool direction = false;
    uint64_t count = 0;
    uint64_t tmp_rotation;

    get_rotation_and_number(str, &direction, &count);
}

void reset(){
    number_of_hits = 0;
    rotation = 50;
}
