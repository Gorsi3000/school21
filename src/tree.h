#ifndef TREE_H
#define TREE_H

typedef struct tree_node {
    struct tree_node *left;
    struct tree_node *right;
    int item;
} tree_node;

tree_node *tree_node_create(int item);

void tree_node_insert(tree_node **root, int item, int (*cmpf)(int, int));
void tree_apply_infix(tree_node *root, void (*applyf)(int));
void tree_apply_prefix(tree_node *root, void (*applyf)(int));
void tree_apply_postfix(tree_node *root, void (*applyf)(int));
// int	bstree_strcmp(char *str1, char *str2);
#endif