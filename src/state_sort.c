#include "tuple.h"
#include "crudl.h"
#include <stdlib.h>
#include <string.h>

void output_menu();
void output_tuple(tuple t);

int main(void) {
    output_menu();
    int num;
    input_num(&num);

    switch (num)
    {
    case /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }


    return 0;
}

void output_db(FILE* file){
    int count = get_records_count_in_file(file);
    int i = -1;
    while (i++ < count)
    {
        tuple* t = read_record_from_file(file, i);
        output_tuple(t);
        free(t);
    }
}

void sort_db(FILE* file){
    int count = get_records_count_in_file(file);
    int i = -1;
    while (++i < count - 1)
    {
        int j = -1;
        while (++j < count - i - 1) {
            tuple* t1 = read_record_from_file(file, j);
            tuple* t2 = read_record_from_file(file, j + 1);

            if (compare_date_time(t1, t2) > 0) swap_records_in_file(file, t1, t2, j, j +1);

            free(t1);
            free(t2);
        }
    }
}

int compare_date_time(tuple* t1, tuple* t2) {
    char* date_time1[30];
    sscanf(date_time1, "%04d-%02d-%02d %02d:%02d:%02d", 
            t1->year, t1->month, t1->day, t1->hour, t1->minute, t1->second);
    char* date_time2[30];
    sscanf(date_time2, "%04d-%02d-%02d %02d:%02d:%02d", 
            t2->year, t2->month, t2->day, t2->hour, t2->minute, t2->second);
    return strcmp(date_time1, date_time2);
}

void output_tuple(tuple* t) {
    printf("%d %d %d %d %d %d %d %d",
            t->year, t->month, t->day, t->hour, 
            t->minute, t->second, t->status, t->code);
}
