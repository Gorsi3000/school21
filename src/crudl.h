#pragma once 

#include "entity.h"

entity* read_record_from_file(FILE *pfile, int index, entity e);
void write_record_in_file(FILE *pfile, const entity *record_to_write, int index);
void swap_records_in_file(FILE *pfile, entity* t1, entity* t2, int index1, int index2)
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);
