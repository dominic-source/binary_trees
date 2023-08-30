#include "binary_trees.h"

/**
 * binary_tree_uncle - find the uncle of a node
 * @node: a pointer to the uncle
 *
 * Return: a pointer to uncle or NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *g_parent, *parent;

	if (node == NULL)
		return (NULL);
	parent = node->parent;
	if (parent == NULL)
		return (NULL);
	g_parent = node->parent->parent;
	if (g_parent == NULL)
		return (NULL);

	if (g_parent->left == parent)
		return (g_parent->right);
	return (g_parent->left);
}
