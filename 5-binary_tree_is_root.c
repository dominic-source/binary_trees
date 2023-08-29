#include "binary_trees.h"

/**
 * binary_tree_is_root - check if a tree is the root
 * @node: the node of the tree
 * Return: 1 or 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->parent != NULL)
		return (0);
	return (1);
}
