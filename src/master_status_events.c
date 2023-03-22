#include "master_status_events.h"

#include <stdio.h>

void print_events(FILE *fptr, int fields_count) {
    struct event record;
    for (int i = 0; i <= fields_count - 1; i++) {
        record = read_record_events(fptr, i);
        printf("%d %d %d %s %s\n", record.event_id, record.module_id, record.new_module_status,
               record.status_change_date, record.status_change_time);
    }
}

struct event read_record_events(FILE *fptr, int index) {
    int offset = index * sizeof(struct event);
    fseek(fptr, offset, SEEK_SET);
    struct event record;
    fread(&record, sizeof(struct event), 1, fptr);
    rewind(fptr);
    return record;
}

int count_events(FILE *fptr) { return get_events_size(fptr) / sizeof(struct event); }

int get_events_size(FILE *fptr) {
    int size;
    fseek(fptr, 0, SEEK_END);
    size = ftell(fptr);
    rewind(fptr);
    return size;
}
