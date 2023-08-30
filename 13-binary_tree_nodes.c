#include "binary_trees.h"

/**
 * binary_tree_nodes - counts sthe nodes with at least one child in a tree
 * @tree: a pointer to the tree node
 *
 * Return: counts or 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL || tree->right != NULL)
		nodes += 1;

	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);

	return (nodes);
}
