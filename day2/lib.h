#ifndef __DAY2_LIB_H
#define __DAY2_LIB_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint64_t min;
    uint64_t max;
} range_t;

uint64_t get_total();

void add_invalid_values_in_range(char *str);
bool get_min_max(char *str, uint64_t *min, uint64_t *max);

void run_part1(char **data, uint64_t size);
void run_part2(char **data, uint64_t size);
void count_rotation_dumb(char *str);

// Really just for unit testing
void reset();

#endif // __DAY2_LIB_H
