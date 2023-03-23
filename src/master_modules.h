#include <stdio.h>

#ifndef T15D24_1_MASTER_MODULES_H
#define T15D24_1_MASTER_MODULES_H

typedef struct module {
    int module_id;
    char module_name[30];
    int number_of_memory;
    int number_of_cells;
    int d_flag;
} module;

void print_modules(FILE *fptr, int fields_count);
int count_modules(FILE *fptr);
struct module read_record_modules(FILE *fptr, int index);
int get_modules_size(FILE *fptr);

#endif
