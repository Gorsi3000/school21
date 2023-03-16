#include "list.h"
#include <stdlib.h>
#define STACK_OVERFLOW 1


// initialization of the singly linked list
struct node* init(struct door* door){
    Node* new_node = NULL;
    new_node = (Node*) malloc(sizeof(Node));
    if (!new_node)
        exit(STACK_OVERFLOW);
    
    new_node->door = door;
    new_node->next = NULL;
    return new_node;
}

// inserting a new struct door element into a singly linked list 
struct node* add_door(struct node* elem, struct door* door){
    Node* new_node = init(door);
    new_node->next = elem->next;
    elem->next = new_node;
    return new_node;
}

// search for a door in the list by its id
struct node* find_door(int door_id, struct node* root) {
    Node* ret = root;
    while(ret)
        if (ret->door->id == door_id) break;
        else ret = ret->next;
    return ret;
}

//deleting a list element
struct node* remove_door(struct node* elem, struct node* root) {
    Node* tmp = root;
    if (elem == tmp)
        root = root->next;
    else
        while (tmp)
        {
            if (tmp->next != elem) tmp = tmp->next;
            else {
                tmp->next = tmp->next->next;
                tmp = elem;
                break;
            }
        }
    if (tmp) {
        if (tmp->door) free(tmp->door);
        free(tmp);
    }
    return root;    
}

// freeing the memory occupied by the list structure
void destroy(struct node* root) {
    while(root){
        Node* tmp = root->next;
        if(root->door) free(root->door);
        free(root);
        root = tmp;
    }
}
