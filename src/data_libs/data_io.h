#ifndef DATA_IO_H
#define DATA_IO_H

#define input_num(X)            \
    _Generic((X),               \
    int*: input_num_int,        \
    double*: input_num_double,  \
    default: input_num_int      \
)(X)

int input(double **data,int *n);
int input_num_double(double* num);
int input_num_int(int* num);
int input_data(double* data, int lenght);

void output(double* _data, int lenght);
void output_error();

void free_memory(double** data);
int allocate_memory(double** arr, int lenght);

#endif
