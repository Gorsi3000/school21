#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define SUCCESS printf("SUCCESS\n")
#define FAIL printf("FAIL\n")

Node* prepare_list();
int list_length(Node* root);
Door* new_door(int id);

void add_door_test();
void remove_door_test();

int main(void) {
    add_door_test();
    remove_door_test();
    return 0;
}

void assert(int compare_result) {
    if (compare_result) SUCCESS;
    else FAIL;
}

void add_door_test() {
    Node* root1 = prepare_list(5);

    add_door(root1, new_door(10));
    assert(list_length(root1) == 6);
    assert(add_door(root1, new_door(11)) != NULL);

    destroy(root1);
}

void remove_door_test() {
    Node* root = prepare_list(5);
    Node* tmp = root;

    assert(list_length(remove_door(root->next->next, root)) == 4);
    root = remove_door(root, root);
    assert(root != tmp);

    destroy(root);
}

int list_length(Node* root) {
    int count = 0;
    while (root) {
        root = root->next;
        ++count;
    }
    return count;
}

Door* new_door(int id) {
    Door* d = malloc(sizeof(Door));
    d->id = id;
    d->status = id%2;
    return d;
}

Node* prepare_list(int lenght){
    int i = 0;
    Node* root = NULL;
    while (i++ < lenght) {
        if (i == 1) root = init(new_door(i));
        else add_door(root, new_door(i));
    }
    return root;
}

