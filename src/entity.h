#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include "master_levels.h"
#include "master_modules.h"
#include "master_status_events.h"

#define dbfile(x) \
    _Generic((x), \
        module: "../materials/master_modules.db", \
        levels: "../materials/master_levels.db",\
        event: "../materials/master_status_events.db")

#define insert(x) \
    _Generic ((x), \
        module: insert_module,\
        levels: insert_level, \
        event: inset_event) (x)

#define entity(x) \
    _Generic((x), 
        module: struct module,\
        levels: struct level, \
        event: struct event)

#define DBFILE()
int insert(FILE *db, entity *entity);
#endif