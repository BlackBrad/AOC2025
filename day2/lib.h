#ifndef __DAY1_LIB_H
#define __DAY1_LIB_H

#include <stdint.h>
#include <stdbool.h>

void run_part1(char **data, uint64_t size);
void run_part2(char **data, uint64_t size);
void count_rotation_dumb(char *str);

// Really just for unit testing
void reset();

#endif // __DAY1_LIB_H
