#include "master_modules.h"

#include <stdio.h>

void print_modules(FILE *fptr, int fields_count) {
    struct module record;
    for (int i = 0; i <= fields_count - 1; i++) {
        record = read_record_modules(fptr, i);
        printf("%d %s %d %d %d\n", record.module_id, record.module_name, record.number_of_memory,
               record.number_of_cells, record.d_flag);
    }
}

struct module read_record_modules(FILE *fptr, int index) {
    int offset = index * sizeof(struct module);
    fseek(fptr, offset, SEEK_SET);
    struct module record;
    fread(&record, sizeof(struct module), 1, fptr);
    rewind(fptr);
    return record;
}

int count_modules(FILE *fptr) { return get_modules_size(fptr) / sizeof(struct module); }

int get_modules_size(FILE *fptr) {
    int size;
    fseek(fptr, 0, SEEK_END);
    size = ftell(fptr);
    rewind(fptr);
    return size;
}