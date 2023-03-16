#ifndef LIST_H
#define LIST_H

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

// initialization of the singly linked list
struct node* init(struct door* door);

// inserting a new struct door element into a singly linked list 
struct node* add_door(struct node* elem, struct door* door);

// search for a door in the list by its id
struct node* find_door(int door_id, struct node* root);

//deleting a list element
struct node* remove_door(struct node* elem, struct node* root);

// freeing the memory occupied by the list structure
void destroy(struct node* root);

#endif