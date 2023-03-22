#include <stdio.h>
#include <string.h>
#ifndef T15D24_1_TEST_H
#define T15D24_1_TEST_H

struct event;

void select(int table, int id);
struct module* select_module(FILE* fptr, int id, struct module* result);
struct level* select_level(FILE* fptr, int id, struct level* result);
struct event* select_event(FILE* fptr, int id, struct event* result);

#endif
