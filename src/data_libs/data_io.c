#include <stdio.h>
#include <stdlib.h>
#include "data_io.h"

void output(double* data, int lenght) {
    for (int i = 0; i < lenght; i++)
        printf(i == lenght - 1 ? "%.2lf" : "%.2lf ", data[i]);
}

void output_error() { printf("n/a"); }


void free_memory(double** data) {
    free(*data);
    *data = NULL;
}

int allocate_memory(double** arr, int lenght) {
    int ret = -1;
    double* rows_arr = malloc(lenght * sizeof(double)); 
    if (rows_arr ) {
        *arr = rows_arr;
        ret = 0;
    }
    return ret;
}

int input(double** data, int* lenght) {
    int ret = -1;
    if (input_num(lenght) == 0 && *lenght > 0) {
        double* _new = NULL;
        if (!allocate_memory(&_new, *lenght)) {
            if (!input_data(_new, *lenght))
                free_memory(&_new);
            else {
                *data = _new;
                ret = 0;
            }
        }
    }
    return ret;
}

int input_num_double(double* num) { return scanf("%lf", num) != 1; }
int input_num_int(int* num) { return scanf("%d", num) != 1; }

int input_data(double* data, int lenght) {
    int ret = 0;
    for (int i = 0; i < lenght; i++) {
        if (input_num(&data[i])) {
            ret = -1;
            break;
        }
    }
    return ret;
}

