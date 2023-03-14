#include <stdlib.h>
#include "data_process.h"
#include "data_io.h"

int main()
{
    int n, ret = -1;
    double *data = NULL;
    
    ret = input(&data, &n);

    if (!ret && !(ret = normalization(data, n)))
        output(data, n);
    else
        output_error();

    if (data) free_memory(&data);

    return ret;  
}

