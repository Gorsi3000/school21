#include <stdio.h>

#ifndef T15D24_1_MASTER_STATUS_EVENTS_H
#define T15D24_1_MASTER_STATUS_EVENTS_H

struct event {
    int event_id;
    int module_id;
    int new_module_status;
    char status_change_date[11];
    char status_change_time[9];
};

void print_events(FILE *fptr, int fields_count);
int count_events(FILE *fptr);
struct event read_record_events(FILE *fptr, int index);
int get_events_size(FILE *fptr);

#endif
