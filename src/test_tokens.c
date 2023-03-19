#include "input.h"
#include <stdlib.h>

int main(void)
{
    lexema** in = input();

    int i = 0;
    while(in[i]->type != end) free(in[i]);
    free(in);
    return 0;
}