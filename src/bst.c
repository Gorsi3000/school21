#include "bst.h"
#include <stdlib.h>

t_btree *bstree_create_node(int item) {
	t_btree	*node = NULL;

	if (node = malloc(sizeof(node)))
    {	node->item = item;
        node->left = NULL;
        node->right = NULL;
    }	
return (node); 
}

void bstree_insert(t_btree *root, int item, int (*cmpf) (int, int)) {
    t_btree *node = bstree_create_node(item);
    t_btree	*current = root;
	if (cmpf(item, current->item) < 0)
	{
		if (current->left)
			btree_insert_data(&current->left, item, cmpf);
		else
			current->left = btree_create_node(item);
	}
	else
	{
		if (current->right)
			btree_insert_data(&current->right, item, cmpf);
		else
			current->right = btree_create_node(item);
	}
}

void bstree_apply_prefix(t_btree *root, void (*applyf) (int)){
	applyf(root->item);
	if (root->left)
		btree_apply_prefix(root->left, applyf);
	if (root->right)
		btree_apply_prefix(root->right, applyf);
}

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root->left)
		btree_apply_infix(root->left, applyf);
	applyf(root->item);
	if (root->right)
		btree_apply_infix(root->right, applyf);
}


void bstree_apply_postfix(t_btree *root, void (*applyf) (int)){
{
	if (root->left)
		btree_apply_suffix(root->left, applyf);
	if (root->right)
		btree_apply_suffix(root->right, applyf);
	applyf(root->item);
}