#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert node to the left of the parent
 *
 * @parent: the parent node of the tree or subtree
 * @value: the key of the node
 *
 * Return: NULL or pointer to the created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->right = NULL;
	node->parent = parent;
	node->left = NULL;

	if (parent->left != NULL)
	{
		node->left = parent->left;
		parent->left->parent = node;
	}
	parent->left = node;

	return (node);
}
