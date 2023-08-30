#include "binary_trees.h"

/**
 * binary_tree_height - find the height of a binary tree
 * @tree: a pointer to the tree
 * Return: the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftH, rightH;

	if (tree == NULL)
		return (0);
	leftH = binary_tree_height(tree->left);
	rightH = binary_tree_height(tree->right);

	return ((leftH > rightH ? leftH : rightH) + 1);
}
