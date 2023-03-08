#include <stdio.h>

#define NMAX 100

void print(int a[]);

void main () {
    int a[] = {1, 9, 4, 4, 6, 7, 4, 4, 0, 7, 3, 7, 0, 9, 5, 5, 1, 6, 1};
    int c[] = {1, 9, 4, 4, 6, 7, 4, 4, 0, 7, 3, 7, 0, 9, 5, 5, 1, 6, 1};
    int b[NMAX] = {2, 9};

    int aLen = NMAX;
    int bLen = NMAX;
    
    int i = 0;
    // while ( i++ < 5) {
    //     scanf("%d", a[i]);i
    // }
    // i = 0;
    // while ( i++ < 5) {
    //     scanf("%d", b[i]);
    // }

    for (int i = 0; i < NMAX; i++ ) {
        if (c[i] < b[i]) {
            int j = i - 1;
            for (; j >= 0; --j)
                if (c[j] != 0) {
                    --c[j];
                    while (++j + i <= aLen)
                        c[j] += j == aLen - 1 ? 10 : 9;
                    
                    break;
                } 
            if (j == -1)
                return;
        }
        // else 
        //     c[i] = a[i];
        c[i] -= b[i];
    }

    print(a);
    print(b);
    print(c);

}

void print(int a[]) {
    for (int i = 0; i < NMAX; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int ret = fflush(stdout);

}