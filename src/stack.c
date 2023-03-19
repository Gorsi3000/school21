#include "stack.h"

#include <stdlib.h>
#define STACK_OVERFLOW 1
#define STACK_UNDERFLOW 2

node* stack_node_create(lexema* lex) {
    node* new_node = NULL;
    new_node = (node*)malloc(sizeof(node));
    if (!new_node) exit(STACK_OVERFLOW);

    new_node->lex = lex;
    new_node->next = NULL;
    return new_node;
}

node* stack_push(node** head, lexema* lex) {
    node* new_node = stack_node_create(lex);
    if (head) {
        new_node->next = (*head);
    }
    (*head) = new_node;
    return *head;
}

lexema* stack_pop(node** head) {
    node* tmp = (*head)->next;
    lexema* val = (*head)->lex;
    // if ((*head)->next == NULL) {
    //     exit(STACK_UNDERFLOW);
    // }
    free(*head);
    (*head) = tmp;
    return val;
}
