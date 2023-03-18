#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

char* print_res(const tree_node** arr, int num);
void _assert(const tree_node** arr, int num, char* expected);

int main(void) {
    tree_node* arr[3];

    arr[0] = tree_node_create(5);
    _assert((const tree_node**)arr, 1, "5");

    arr[1] = tree_node_create(5);
    _assert((const tree_node**)arr, 2, "5, 5");

    arr[2] = tree_node_create(7);
    _assert((const tree_node**)arr, 3, "5, 5, 7");

    for (int i = 0; i < 3; i++) free(arr[i]);
}
void _assert(const tree_node** arr, int num, char* expected) {
    char* out = print_res(arr, num);
    printf("%-10s in: '%-10s' out: '%s'\n", strcmp(out, expected) == 0 ? "SUCCESS" : "FAIL", out, expected);
    free(out);
}

char* print_res(const tree_node** arr, int num) {
    char* buffer = NULL;
    buffer = (char*)malloc(sizeof(char) * 10);
    if (!buffer) exit(-1);
    int i = 0;
    buffer[0] = '\0';
    while (i < num) {
        char tmp[10];
        sprintf(tmp, (i == num - 1 ? "%d%c" : "%d, %c"), arr[i]->item, '\0');
        buffer = strcat(buffer, tmp);
        i++;
    }
    return buffer;
}
