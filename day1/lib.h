#ifndef __DAY1_LIB_H
#define __DAY1_LIB_H

#include <stdint.h>
#include <stdbool.h>

#define MAX_ROTATION 99

#define COUNT_UP true
#define COUNT_DOWN false

uint64_t get_number_of_hits();
uint64_t get_rotation();
void get_rotation_and_number(char *, bool *direction, uint64_t *rotation_count);
void count_rotation(char *, bool part_2);

void run_part1(char **data, uint64_t size);
void run_part2(char **data, uint64_t size);
void count_rotation_dumb(char *str);

// Really just for unit testing
void reset();
void set_rotation_count(uint64_t rotation_count);

#endif // __DAY1_LIB_H
