#include "binary_trees.h"

/**
 * binary_tree_depth - the depth of the binary tree
 *
 * @tree: a pointer to root of the tree
 * Return: depth or 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent != NULL)
	{
		tree = tree->parent;
		depth += 1;
	}
	return (depth);
}
