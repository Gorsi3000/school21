#include <stdio.h>

#ifndef T15D24_1_MASTER_LEVELS_H
#define T15D24_1_MASTER_LEVELS_H

typedef struct level {
    int number_of_memory;
    int number_of_cells;
    int d_flag;
} levels;

void print_levels(FILE *fptr, int fields_count);
int count_levels(FILE *fptr);
struct level read_record_levels(FILE *fptr, int index);
int get_levels_size(FILE *fptr);

#endif
