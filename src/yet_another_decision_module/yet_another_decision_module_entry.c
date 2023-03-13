#include <stdlib.h>
#include <stdio.h>
#include "decision.h"
#include "data_io.h"

int main()
{
    double *data = NULL;
    int n;

    int ret = !input(&data, &n);
    
    if (!ret && !(ret = make_decision(data, n)))
        printf("YES"); 
    else
        printf("NO");  

    return ret;
}
