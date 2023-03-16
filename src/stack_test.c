#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define SUCCESS printf("SUCCESS\n")
#define FAIL printf("FAIL\n")

Node* prepare_stack();
int stack_length(Node* root);
Door* new_door(int id);

void push_test();
void pop_test();

int main(void) {
    push_test();
    pop_test();
    return 0;
}

void assert(int compare_result) {
    if (compare_result) SUCCESS;
    else FAIL;
}

void push_test() {
    Node* head = prepare_stack(5);

    Node* new_head = push(head, new_door(10));
    assert(new_head->door->id == 10);
    assert(stack_length(new_head) == 6);
    assert(new_head->next == head);

    head = push(new_head, NULL);
    assert(head->door == NULL);

    destroy(head);
}

void pop_test() {
    Node* head = prepare_stack(5);
    Node* tmp = head;

    Door* d = head->door;
    Door* next_d = head->next->door;
    Node* next_n = head->next;
    assert(pop(head) == d);
    assert(head == next_n);
    free(d);
    destroy(head);

    head = prepare_stack(1);
    free(pop(head));
    assert(head == NULL);
    if (head) destroy(head);
}

int stack_length(Node* head) {
    int count = 0;
    while (head) {
        head = head->next;
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

Node* prepare_stack(int lenght){
    int i = 0;
    Node* root = NULL;
    while (i++ < lenght) {
        if (i == 1) root = init(new_door(i));
        else push(root, new_door(i));
    }
    return root;
}

