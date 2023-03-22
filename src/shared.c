#include "shared.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "master_levels.h"
#include "master_modules.h"
#include "master_status_events.h"

void select(int table, int id) {
    switch (table) {
        case 1: {
            FILE* fptr = fopen("../materials/master_modules.db", "r+b");
            struct module* result = malloc(sizeof(struct module));
            result->module_id = -1;
            if (id == -1) {
                int fields_count = count_modules(fptr);
                for (int i = 0; i < fields_count; i++) {
                    select_module(fptr, i, result);
                    printf("\n%d %s %d %d %d\n", result->module_id, result->module_name,
                           result->number_of_memory, result->number_of_cells, result->d_flag);
                }
            } else {
                select_module(fptr, id, result);
                if (result->module_id != -1) {
                    printf("\n%d %s %d %d %d\n", result->module_id, result->module_name,
                           result->number_of_memory, result->number_of_cells, result->d_flag);
                } else {
                    printf("\nNo such row in the table!\n");
                }
            }
            fclose(fptr);
            free(result);
            break;
        }
        case 2: {
            FILE* fptr = fopen("../materials/master_levels.db", "r+b");
            struct level* result = malloc(sizeof(struct level));
            result->number_of_memory = -1;
            if (id == -1) {
                int fields_count = count_levels(fptr);
                for (int i = 1; i < fields_count + 1; i++) {
                    select_level(fptr, i, result);
                    printf("\n%d %d %d\n", result->number_of_memory, result->number_of_cells, result->d_flag);
                }
            } else {
                select_level(fptr, id, result);
                if (result->number_of_memory != -1) {
                    printf("\n%d %d %d\n", result->number_of_memory, result->number_of_cells, result->d_flag);
                } else {
                    printf("\nNo such row in the table!\n");
                }
            }
            fclose(fptr);
            free(result);
            break;
        }
        case 3: {
            FILE* fptr = fopen("../materials/master_status_events.db", "r+b");
            struct event* result = malloc(sizeof(struct event));
            result->event_id = -1;
            if (id == -1) {
                int fields_count = count_events(fptr);
                for (int i = 0; i < fields_count; i++) {
                    select_event(fptr, i, result);
                    printf("\n%d %d %d %s %s\n", result->event_id, result->module_id,
                           result->new_module_status, result->status_change_date, result->status_change_time);
                }
            } else {
                select_event(fptr, id, result);
                if (result->event_id != -1) {
                    printf("\n%d %d %d %s %s\n", result->event_id, result->module_id,
                           result->new_module_status, result->status_change_date, result->status_change_time);
                } else {
                    printf("\nNo such row in the table!\n");
                }
            }
            fclose(fptr);
            free(result);
            break;
        }
    }
}

struct module* select_module(FILE* fptr, int id, struct module* result) {
    int fields_count = count_modules(fptr);
    struct module record;
    for (int i = 0; i <= fields_count; i++) {
        record = read_record_modules(fptr, i);
        if (record.module_id == id) {
            result->module_id = record.module_id;
            strcpy(result->module_name, record.module_name);
            result->number_of_memory = record.number_of_memory;
            result->number_of_cells = record.number_of_cells;
            result->d_flag = record.d_flag;
        }
    }
    return result;
}

struct level* select_level(FILE* fptr, int id, struct level* result) {
    int fields_count = count_levels(fptr);
    struct level record;
    for (int i = 0; i <= fields_count; i++) {
        record = read_record_levels(fptr, i);
        //        printf("%d %d %d\n", i, id, record.number_of_memory);
        if (record.number_of_memory == id) {
            result->number_of_memory = record.number_of_memory;
            result->number_of_cells = record.number_of_cells;
            result->d_flag = record.d_flag;
        }
    }
    return result;
}

struct event* select_event(FILE* fptr, int id, struct event* result) {
    int fields_count = count_events(fptr);
    struct event record;
    for (int i = 0; i <= fields_count; i++) {
        record = read_record_events(fptr, i);
        if (record.event_id == id) {
            result->event_id = record.event_id;
            result->module_id = record.module_id;
            result->new_module_status = record.new_module_status;
            strcpy(result->status_change_date, record.status_change_date);
            strcpy(result->status_change_time, record.status_change_time);
        }
    }
    return result;
}