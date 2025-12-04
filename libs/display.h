#ifndef _DISPLAY_H
#define _DISPLAY_H

#include <stdint.h>
#include <stdbool.h>

void display_word(uint16_t word, bool reset_display);
void display(uint64_t value);

#endif
