#include <stdio.h>
#include <stdlib.h>

void swap(int* xp, int* yp);
void selectionSort(int arr[], int n);
void print(int* arr, int size);
void print(int* a, int len);
void printError();
int inputArray(int* buff1, int lenght);
int inputNum(int *n);

int main() {
    int* arr;
    int len;
    int ret = 0;
    printf("%d", !(-1));
    if (inputNum(&len) == 0) {
        if ((ret = inputArray(arr, len)) == 0 ) {
            selectionSort(arr, len);
            print(arr, len);
            free(arr);
        }
    } 
    
    if (ret != 0) printError();

    return 0;
}

int inputNum(int* num)
{

}

int inputArray(int* buff1, int lenght) {
    int ret = 0;
    char c;
    int count = 0;
    buff1 = (int*) malloc(lenght * sizeof(int));

    if (buff1 != NULL) {
        do {
            int result = scanf("%d%c", &buff1[count], &c);
            if (result != 2 || (c != ' ' && c != '\n')) {
                ret = -1;
                break;
            }
            ++count;
        } while (c != '\n' && count < lenght);
    }
    
    if (c != '\n' || count != lenght) {
        if (buff1 != NULL)
            free(buff1);
        ret = -1; 
    }
    return ret;
}

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int* arr, int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void print(int* arr, int size) {
    int i;
    for (i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

void printError() { printf("n/a"); }
