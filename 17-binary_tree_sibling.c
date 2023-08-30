#include "binary_trees.h"

/**
 * binary_tree_sibling - find the sibling of a node
 * @node: find the sibling of a node
 *
 * Return: NULL or pointer to the node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
