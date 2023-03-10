#include<stdio.h>
#include<stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/
int** sort_vertical(int **matrix, int n, int m);

/*
    1 2 3
    6 5 4
    7 8 9
*/
int** sort_horizontal(int **matrix, int n, int m);
int** sort(int **matrix, int n, int m, int asc);
void sort_array(int* arr, int length, int asc);
int** copy(int **matrix, int rows, int cols);

int input(int ***matrix, int *n, int *m);
void output(int** matrix, int rows, int cols);
int input_num(int* num);
int input_data(int** matrix, int rows, int cols);
void print_error();

int allocate_memory(int*** arr, int rows, int cols);
void free_memory(int*** matrix);

void main()
{
    int **matrix = NULL, **result = NULL;
    int rows, cols, ret;

    if ((ret = input(&matrix, &rows, &cols)) == 0) {
        result = sort_vertical(matrix, rows, cols);
        if (!(ret = result == 0)) {
            output(result, rows, cols);
            free_memory(&result);
        }

        printf("\n");
        
        // result = sort_horizontal(matrix, rows, cols);
        // if (!(ret = result == 0)) output(result, rows, cols);
    }
    if (ret != 0) print_error();
    if (matrix != NULL) free_memory(&matrix);
    if (result != NULL) free_memory(&result);
}

int** copy(int **matrix, int rows, int cols) {
    int** new_m = NULL;
    allocate_memory(&new_m, rows, cols);
    int* ptr_from = matrix[0];
    int* ptr_to = new_m[0];
    for (int i = 0; i < rows * cols; i++)
        ptr_to[i] = ptr_from[i];
    return new_m;
}

int** sort(int **matrix, int rows, int cols, int asc) {
    int** new_matrix = copy(matrix, rows, cols);
    int* ptr_start = new_matrix[0];
    sort_array(ptr_start, rows * cols, asc);
    return new_matrix;
}

void sort_array(int* arr, int length, int asc){
   int factor = asc > 0 ? 1 : -1;
    for (int i = 0; i < length - 1; i++)
        for (int j = 0; j < length - i - 1; j++) {
            if (factor * arr[j] > factor * arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
}

int** sort_horizontal(int **matrix, int n, int m) {
    int** sorted = sort(matrix, n, m, 1);
    if (sorted != NULL)
        for (int i = 1; i < n; i += 2)
            sort_array(sorted[i], m, -1);
    return sorted;
}

int** sort_vertical(int **matrix, int n, int m) {
    int** sorted = sort(matrix, n, m, 1);
    if (sorted != NULL){
        int* ptr_start = sorted[0];
        for (int i = 1; i < n * m; i++) {
                int tmp = ptr_start[i * row ];
                p[i] = 
                sorted[i][j] = sorted[j][i];
                sorted[j][i] = tmp;
            }
    }
    return sorted;
    
}

void free_memory(int*** arr) {
    free((*arr)[0]);
    free(*arr);
    *arr = NULL;
}

int allocate_memory(int*** arr, int rows, int cols) {
    int ret = -1;
    int** rows_arr = (int**)malloc(rows * sizeof(int*));
    if (rows_arr != NULL) {
        int* cols_arr = (int*)malloc(rows * cols * sizeof(int));
        if (cols_arr == NULL) 
            free(rows_arr);
        else {
            for (int i = 0; i < rows; i++) {
                rows_arr[i] = cols_arr + i * cols;
            }
            *arr = rows_arr;
            ret = 0;
        }
    } 
    return ret;
}

void output(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            printf(j == cols - 1 ? (i == rows - 1 ? "%d" : "%d\n") : "%d ", matrix[i][j]);
}

void print_error() { printf("n/a"); }

int input(int*** matrix, int* rows, int* cols) {
    int ret = -1;
    if (input_num(rows) == 0 && input_num(cols) == 0) {
        int** new_m = NULL;
        if (allocate_memory(&new_m, *rows, *cols) == 0) {
            if (input_data(new_m, *rows, *cols) != 0)
                free_memory(&new_m);
            else {
                *matrix = new_m;
                ret = 0;
            }
        }
    }
    return ret;
}

int input_num(int* num) {
    return scanf("%d", num) != 1;
}

int input_data(int** matrix, int rows, int cols) {
    int ret = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &(matrix[i][j])) != 1) {
                ret = -1;
                break;
            }
        }
    }
    return ret;
}

