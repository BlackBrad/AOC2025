#ifndef __DAY1_LIB_H
#define __DAY1_LIB_H

#include <stdint.h>
#include <stdbool.h>

#include "data.h"

#define MAX_ROTATION 99

#define COUNT_UP true
#define COUNT_DOWN false

uint64_t get_number_of_hits();
uint64_t get_rotation();
void get_rotation_and_number(char *, bool *direction, uint64_t *rotation_count);
void count_rotation(char *);

void run(char **data, uint64_t size);

// Really just for unit testing
void reset();

#endif // __DAY1_LIB_H
