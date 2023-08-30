#include "binary_trees.h"

/**
 * binary_tree_size - find the size of the binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: size of tree or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (tree == NULL)
		return (0);
	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);

	return (size);
}
