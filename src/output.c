#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
} Point;

void output(Point *out, int n) {
    int **matrix = (int **)calloc(25, sizeof(int *));
    for (int i = 0; i < 25; i++) {
        matrix[i] = (int *)calloc(80, sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        int index_i = out[i].y;
        int index_j = out[i].x;
        matrix[index_i][index_j] = 1;
    }

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            matrix[i][j] == 1 ? printf("*") : printf(".");
        }
        if (i+1 != 25)
            printf("\n");
    }

    for (int i = 0; i < 25; i++) {
        free(matrix[i]);
    }
    free(matrix);
}