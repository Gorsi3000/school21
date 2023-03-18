#include "bst.h"

#include <stdlib.h>

tree_node *tree_node_create(int item) {
    tree_node *node = NULL;

    if ((node = malloc(sizeof(tree_node)))) {
        node->item = item;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void tree_node_insert(tree_node **root, int item, int (*cmpf)(int, int)) {
    tree_node *current = root;
    if (!root)
        *root = tree_node_create(item);
    else if (cmpf(item, current->item) < 0) {
            if (current->left)
                tree_node_insert(current->left, item, cmpf);
            else
                current->left = tree_node_create(item);
        } else {
            if (current->right)
                tree_node_insert(current->right, item, cmpf);
            else
                current->right = tree_node_create(item);
    }
}

void tree_apply_prefix(tree_node *root, void (*applyf)(int)) {
    applyf(root->item);
    if (root->left) tree_apply_prefix(root->left, applyf);
    if (root->right) tree_apply_prefix(root->right, applyf);
}

void tree_apply_infix(tree_node *root, void (*applyf)(int)) {
    if (root->left) tree_apply_infix(root->left, applyf);
    applyf(root->item);
    if (root->right) tree_apply_infix(root->right, applyf);
}

void bstree_apply_postfix(tree_node *root, void (*applyf)(int)) {
    if (root->left) bstree_apply_postfix(root->left, applyf);
    if (root->right) bstree_apply_postfix(root->right, applyf);
    applyf(root->item);
}

// int	bstree_strcmp(char *str1, char *str2) {
// 	int	i= 0;
// 	while (str1[i] != '\0' && str2[i] != '\0')
// 	{
// 		if (str1[i] != str2[i])
// 			return (str1[i] - str2[i]);
// 		i++;
// 	}
// 	if ((str1[i] == '\0' && str2[i] != '\0') || (str2[i] == '\0' && str1[i] != '\0'))
// 		return (str1[i] - str2[i]);
// 	return (0);
// }
