#include "stack.h"
#include <stdlib.h>
#define STACK_OVERFLOW 1
#define STACK_UNDERFLOW 2


Node* init(Door* door){
    Node* new_node = NULL;
    new_node = (Node*) malloc(sizeof(Node));
    if (!new_node)
        exit(STACK_OVERFLOW);
    
    new_node->door = door;
    new_node->next = NULL;
    return new_node;
}

Node* push(Node* head, Door* door){
    Node* new_node = init(head->door);
    new_node->next = head->next;
    head->next = new_node;
    head->door = door;
    return head;
}

Door* pop(Node **head) {
    Node *tmp = (*head)->next;
    Door *val = (*head)->door;
    if ((*head)->next == NULL) {
        exit(STACK_UNDERFLOW);
    }
    free(*head);
    (*head) = tmp;
    return val;
}

void destroy(Node* head) {
    while(head){
        Node* tmp = head->next;
        if(head->door) free(head->door);
        free(head);
        head = tmp;
    }
}
