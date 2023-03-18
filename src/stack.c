#include "stack.h"

#include <stdlib.h>
#define STACK_OVERFLOW 1
#define STACK_UNDERFLOW 2

node* stack_init(lexema* lex) {
    node* new_node = NULL;
    new_node = (node*)malloc(sizeof(node));
    if (!new_node) exit(STACK_OVERFLOW);

    new_node->lex = lex;
    new_node->next = NULL;
    return new_node;
}

node* stack_push(node** head, lexema* lex) {
    node* new_node = stack_init((*head)->lex);
    new_node->next = (*head)->next;
    (*head)->next = new_node;
    (*head)->lex = lex;
    return *head;
}

lexema* stack_pop(node** head) {
    node* tmp = (*head)->next;
    lexema* val = (*head)->lex;
    if ((*head)->next == NULL) {
        exit(STACK_UNDERFLOW);
    }
    free(*head);
    (*head) = tmp;
    return val;
}

void stack_destroy(node** head) {
    while (head) {
        node* tmp = (*head)->next;
        if ((*head)->lex) free((*head)->lex);
        free(*head);
        *head = tmp;
    }
}
