#include "master_levels.h"

#include <stdio.h>

void print_levels(FILE *fptr, int fields_count) {
    struct level record;
    for (int i = 0; i <= fields_count - 1; i++) {
        record = read_record_levels(fptr, i);
        printf("%d %d %d\n", record.number_of_memory, record.number_of_cells, record.d_flag);
    }
}

struct level read_record_levels(FILE *fptr, int index) {
    int offset = index * sizeof(struct level);
    fseek(fptr, offset, SEEK_SET);
    struct level record;
    fread(&record, sizeof(struct level), 1, fptr);
    rewind(fptr);
    return record;
}

int count_levels(FILE *fptr) { return get_levels_size(fptr) / sizeof(struct level); }

int get_levels_size(FILE *fptr) {
    int size;
    fseek(fptr, 0, SEEK_END);
    size = ftell(fptr);
    rewind(fptr);
    return size;
}
