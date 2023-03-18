#include "lexema.h"

#ifndef STACK_H
#define STACK_H

typedef struct node {
    struct node* next;
    lexema* lex;
} node;

node* stack_init(lexema* lex);
node* stack_push(node** head, lexema* lex);
lexema* stack_pop(node** head);
void stack_destroy(node** head);

#endif