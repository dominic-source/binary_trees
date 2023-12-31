#include "binary_trees.h"

/**
 * bst_insert - insert node in a binary search tree
 * @tree: a double pointer to the root node
 * @value: the value the node
 * Return: a pointer to the created  node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node, *y, *x = *tree;

	y = NULL;

	node = malloc(sizeof(bst_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	while (x != NULL)
	{
		y = x;
		if (node->n < x->n)
			x = x->left;
		else if (node->n == x->n)
		{
			free(node);
			return (NULL);
		}
		else if (node->n > x->n)
			x = x->right;
	}
	node->parent = y;
	if (y == NULL)
		*tree = node;
	else if (node->n < y->n)
		y->left = node;
	else
		y->right = node;
	return (node);
}
