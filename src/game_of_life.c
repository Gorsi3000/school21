#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void show_matrix(int **field, int cols, int rows);
void speed_show(int millisek);

int** init_state(int rows, int cols);
int input_num(int* num);
int input_data(int** matrix, int rows, int cols);

int evaluate_neighborhood(int** current_state, int rows, int cols, int x, int y);
void evaluate(int** current_state, int** next_state, int rows, int cols);


int** allocate_memory(int rows, int cols);
void free_memory(int*** matrix);

int main() {
    int cols = 30, rows = 10;
    int** current_state = init_state(rows, cols), **next_state = allocate_memory(rows, cols);
    /*
        С матрицей можно работать.
        Тут идут вызовы функций отображения матрицы и другие.
        Надо подумать, как совместить циклы динамической обработки ввода
        и отображения матрицы.

     */
    int counter = 0;
    do {
        // printf("\e[1;1H\e[2J");
        show_matrix(current_state, cols, rows);
        fflush(stdout);
        evaluate(current_state, next_state, rows, cols);

        int** tmp = current_state;
        current_state = next_state;
        next_state = tmp;

        for (int i = 0; i < rows; i++) {
            int last = current_state[i][0];
            for (int j = 0; j < cols - 1; j++) {
                current_state[i][j] = current_state[i][j + 1];
            }
            current_state[i][cols - 1] = last;

            // rand()
        }

        sleep(1);
        ++counter;
    } while (counter != 100);

    free_memory(&current_state);
    free_memory(&next_state);
    return 0;
}

int evaluate_neighborhood(int** current_state, int rows, int cols, int x, int y) {
    int count_neighbours = 0;
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if (i != 0 || j != 0) {
                count_neighbours += current_state[(y + i + rows) % rows][(x + j + cols) % cols];
            }
        }
    }
    return count_neighbours;
}

void evaluate(int** current_state, int** next_state, int rows, int cols) {
    int x, y;

    // for (y = 0; y < rows; ++y) {
    //     for (x = 0; x < cols; ++x) {
    //         next_state[y][x] = current_state[y][x];
    //     }
    // }

    for (y = 0; y < rows; ++y) {
        for (x = 0; x < cols; ++x) {
            int count_neighbours = evaluate_neighborhood(current_state, rows, cols, x, y);

            // next_state[y][x] = current_state[y][x];
            if (count_neighbours == 3) next_state[y][x] = 1;
            if (count_neighbours == 2) next_state[y][x] = current_state[y][x];
            if (count_neighbours < 2 || count_neighbours > 3) next_state[y][x] = 0;
        }
    }
}

int** init_state(int rows, int cols) {
    int** matrix = NULL;
    matrix = allocate_memory(rows, cols);
    input_data(matrix, rows, cols);
    return matrix;
}

void free_memory(int*** arr) {
    free((*arr)[0]);
    free(*arr);
    *arr = NULL;
}

int** allocate_memory(int rows, int cols) {
    int** rows_arr = NULL;
    rows_arr = (int**)malloc(rows * sizeof(int*));
    if (rows_arr != NULL) {
        int* cols_arr = (int*)calloc(rows * cols, sizeof(int));
        if (cols_arr == NULL)
            free(rows_arr);
        else 
            for (int i = 0; i < rows; i++) {
                rows_arr[i] = cols_arr + i * cols;
            }
    }
    return rows_arr;
}

int input_data(int** matrix, int rows, int cols) {
    int ret = 0;

    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //         matrix[i][j] = 0;
    //     }
    // }
    matrix[3][3] = 1;
    matrix[3][4] = 1;
    matrix[3][5] = 1;
    // matrix[4][4] = 1;

    return ret;
}
void show_matrix(int **field, int cols, int rows)
{
    for(int i =0; i < rows; i++)
    {
        for(int j =0; j <cols; j++)
        {
            if(field[i][j] == 1)
                printf("*");
            else
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}
void speed_show(int millisek)
{
    while(1)
    {
        //функция обновления матрицы
        // show_matrix();
        // Sleep(millisek);
    }
    
    
}
