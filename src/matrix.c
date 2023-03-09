#include <stdio.h>
#include <stdlib.h>
#define MAX_DIM 100

int inputNum(int* num);
int dynamicAlloc1(int** arr, int rows, int cols);
int dynamicAlloc3(int** arr, int rows, int cols);
int dynamicAlloc2(int** arr, int rows, int cols);

int main() {
    int choice = -1;
    int ret = 0;
    int** staticArr[MAX_DIM][MAX_DIM];
    int** currArr = NULL;
    ret = inputNum(&choice);
    int cols, rows;
    inputNum();

    switch (choice)
    {
        case 0:
            currArr = staticArr;
            break;
        
        case 1:
            ret = dinamicArray1(currArr, rows, cols);
            break;
        
        case 2:
            ret = dinamicArray2(currArr, rows, cols);
            break;
        
        case 3:
            ret = dinamicArray3(currArr, rows, cols);
            break;
    }


    return ret;
}

int inputNum(int* num) {

}

int dynamicAlloc1(int** arr, int rows, int cols) {
    int ret = 0;
    int** rowsArr = (int*) malloc(rows * sizeof(int*));
    if (rowsArr != NULL) {
        for (int i = 0; i < rows; i++) {
            int* colsArr = (int*) malloc(cols * sizeof(int));
            if (colsArr == NULL) {
                ret = -1;
                --i;
                for (; i >= 0; i--)
                    free(rowsArr[i]);
                free(rowsArr);
                break;
            }
            rowsArr[i] = colsArr;
        }
        arr = rowsArr;
    } else 
        ret = -1;

    return ret;
}

int dynamicAlloc2(int** arr, int rows, int cols) {
    int ret = 0;
    int** rowsArr = (int*) malloc(rows * sizeof(int*));
    if (rowsArr != NULL) {
        int* colsArr = (int*) malloc(rows * cols * sizeof(int));
        if (colsArr == NULL) {
            ret = -1;
            free(rowsArr);
        } else {
            for (int i = 0; i < rows; i++) {
                rowsArr[i] = colsArr + i * cols;
            }
            arr = rowsArr;
        }
    } else 
        ret = -1;

    return ret;
}

int dynamicAlloc3(int** arr, int rows, int cols) {
    int ret = 0;
    int** rowsArr = (int*) malloc(rows * sizeof(int*) + rows * cols * sizeof(int));
    if (rowsArr != NULL) {
        int* dataPtr = rowsArr + rows;
        for (int i = 0; i < rows; i++) {
            rowsArr[i] = dataPtr + i * cols;
        }
        arr = rowsArr;
    } else 
        ret = -1;

    return ret;
}