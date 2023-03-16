#ifndef STACK_H
#define STACK_H

typedef struct door
{
    int id;
    int status;
} Door;

typedef struct node
{
    struct node* next;
    Door* door;
} Node;

Node* init(Door* door);
Node* push(Node* head, Door* door);
Node* pop(Node** head);
void destroy(Node* head);

#endif