#include "lib.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static uint64_t cursor = 0; // The location of the string
static uint64_t total = 0;

uint64_t get_total(){
    return total;
}

uint64_t recur_thingo(uint64_t curr, uint64_t max, int count){
    char tmp1[255] = "";
    //char tmp2[255] = "";

    sprintf(tmp1, "%lld", curr);    
    //sprintf(tmp2, "%lld", max);

    int mod = strlen(tmp1) % count;
    if (mod == 0){
        for (int index = 0; index < strlen(tmp1) / count; index++){
            
        }
    }
}

// Returns false when end of string is reached
bool get_min_max(char *str, uint64_t *min, uint64_t *max){
    uint64_t hiphen_index = 0;
    uint64_t comma_index = 0;
    bool return_value = true;
    char minstr[1000], maxstr[1000];
    memset(minstr, 0, sizeof(minstr));
    memset(maxstr, 0, sizeof(maxstr));

    for (int index = cursor; index < strlen(str); index++) {
        if (str[index] == '-') {
            hiphen_index = index;
        } else if (str[index] == ',') {
            comma_index = index;
            break;
        }
    }

    if (comma_index == 0) {
        comma_index = strlen(str);
        return_value = false;
    }

    strncpy(minstr, &str[cursor], hiphen_index - cursor);
    strncpy(maxstr, &str[hiphen_index + 1], comma_index - hiphen_index);

    *min = strtol(minstr, NULL, 10);
    *max = strtol(maxstr, NULL, 10);

    if (return_value) {
        cursor = comma_index + 1;
    }

    return return_value;
}

void add_invalid_values_in_range(char *str){
    uint64_t min = 0;
    uint64_t max = 0;
    bool more_string = true;

    while(more_string) {
        more_string = get_min_max(str, &min, &max);

        for (int count = min; count <= max; count++) {

        }
    }
}

void run_part1(char **data, uint64_t size) {
    for (int index = 0; index < size; index++){
    }
}

void run_part2(char **data, uint64_t size) {
    for (int index = 0; index < size; index++){
    }
}

void reset(){
    cursor = 0;
    total = 0;
}
