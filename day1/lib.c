#include "lib.h"

#include <stdlib.h>
#include <string.h>

static uint64_t number_of_hits = 0;
static uint64_t rotation = 50;

uint64_t get_number_of_hits(){
    return number_of_hits;
}

uint64_t get_rotation(){
    return rotation;
}

void get_rotation_and_number(char *str, bool *direction, uint64_t *rotation_count){
    char number[255];
    *direction = COUNT_UP;
    
    if (str[0] == 'L') {
        *direction = COUNT_DOWN;
    }

    strcpy(number, &str[1]);
    *rotation_count = (uint64_t)strtol(number, NULL, 10);
}

void count_rotation(char *str, bool part_2){
    bool direction = false;
    uint64_t count = 0;
    uint64_t tmp_rotation = 0;
    int mod = 0, division = 0;
    bool start_zero = (rotation == 0) ? true : false;

    get_rotation_and_number(str, &direction, &count);

    mod = (count % 100);

    if (count >= MAX_ROTATION + 1 && part_2) {
        number_of_hits  += count / MAX_ROTATION;
    }

    if (mod != 0){
        if (direction == COUNT_UP) {
            rotation += mod;
            if (rotation > MAX_ROTATION) {

                rotation -= MAX_ROTATION + 1;

                if (rotation != 0 && part_2 && !start_zero) {
                    number_of_hits += 1;
                }
            }
        } else {
            int64_t temp = rotation - mod;
            if (temp < 0) {
                rotation = 100 - (temp * -1);

                if (rotation != 0 && part_2 && !start_zero) {
                    number_of_hits += 1;
                }
            } else {
                rotation = temp;
            }
        }
    }

    if (rotation == 0 && mod != 0) {
        number_of_hits += 1;
    }
}

void count_rotation_dumb(char *str){
    bool direction = false;
    uint64_t count = 0;
    int tmp_rotation = 0;

    get_rotation_and_number(str, &direction, &count);

    for (int i = 0; i < count; i++){
        if (direction == COUNT_UP) {
            rotation += 1;
            if (rotation > MAX_ROTATION){
                rotation = 0;
                number_of_hits += 1;
            }
        } else {
            tmp_rotation = rotation - 1;

            if (tmp_rotation < 0){
                rotation = MAX_ROTATION;
                number_of_hits += 1;
            } else if (tmp_rotation == 0){
                rotation = tmp_rotation;
                number_of_hits += 1;
            } else {
                rotation = tmp_rotation;
            }
        }
    }
}

void run_part1(char **data, uint64_t size) {
    for (int index = 0; index < size; index++){
        count_rotation(data[index], false);
    }
}

void run_part2(char **data, uint64_t size) {
    for (int index = 0; index < size; index++){
        //count_rotation(data[index], true);
        count_rotation_dumb(data[index]);
    }
}

void set_hit_count(uint64_t hits){
    number_of_hits = hits;
}

void reset(){
    number_of_hits = 0;
    rotation = 50;
}
