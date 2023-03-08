#include <stdio.h>

#define NMAX 100

void print(int a[], int length);

void main () {
    int a[NMAX] = {0};
    int b[NMAX] = {0};
    int c[NMAX] = {0};

    // int init[3][5] = { {1, 0, 0, 0, 1}, {0, 9, 9, 9, 9}, {1, 0, 0, 0, 1}};
    int _a[] = {1, 9, 4, 4, 6, 7, 4, 4, 0, 7, 3, 7, 0, 9, 5, 5, 1, 6, 1};
    int _b[] = {2, 9};
    int _c[] = {1, 9, 4, 4, 6, 7, 4, 4, 0, 7, 3, 7, 0, 9, 5, 5, 1, 6, 1};
    
    for (int i = 0; i < sizeof(_a) / sizeof(int); i++)
        a[i] = _a[i];
    for (int i = 0; i < sizeof(_b) / sizeof(int); i++)
        b[i] = _b[i];
    for (int i = 0; i < sizeof(_c) / sizeof(int); i++)
        c[i] = _c[i];

    int bLen = sizeof(_b) / sizeof(int);//5;//2;//NMAX;
    int aLen = sizeof(_a) / sizeof(int);

    int i = bLen;
    int diff = aLen - bLen;
    if (diff != 0)
        while (--i > -1) {
            b[i + diff] = b[i];
            b[i] = 0;
        }   
    
    
    for (i = 0; i < aLen; i++ ) {
        if (c[i] < b[i]) {
            int j = i;
            while (--j >= 0)
                if (c[j] != 0) {
                    --c[j];
                    while (++j < aLen)
                        c[j] += j == aLen - 1 ? 10 : 9;
                    
                    break;
                } 
            if (j == -1)
                return;
        }
        c[i] -= b[i];
    }

    for (i = aLen - 1; i > -1; i-- ) {
        c[i] = a[i] + b[i];
        if (c[i] > 9) {
            c[i] %= c[i];
            if (i == 0) {
                ++aLen;
                ++i;
                shift(c, -1);
            }
            ++c[i - 1];
        } 
    }


    print(a, aLen);
    print(b, aLen);
    print(c, aLen);

}

void shift(int a[], int size, int diff, int closed)
{
    if (diff == 0) return;

    int i = size;
    while (--i > -1) {
        if (closed)
        b[i + diff]
         = b[i];
        b[i] = 0;
    }   
}

void print(int a[], int length) {
    for (int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int ret = fflush(stdout);

}