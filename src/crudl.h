#include "tuple.h"
#include <stdio.h>

tuple* read_record_from_file(FILE *pfile, int index);
void write_record_in_file(FILE *pfile, const tuple *record_to_write, int index);
void swap_records_in_file(FILE *pfile, tuple* t1, tuple* t2, int index1, int index2)
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);
