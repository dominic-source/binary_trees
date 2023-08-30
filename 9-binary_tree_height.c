#include "binary_trees.h"

/**
 * binary_tree_height2 - find the height of a binary tree
 * @tree: a pointer to the tree
 * Return: the height
 */
size_t binary_tree_height2(const binary_tree_t *tree)
{
	size_t leftH, rightH, height = 0;

	if (tree == NULL)
		return (0);
	leftH = binary_tree_height2(tree->left);
	rightH = binary_tree_height2(tree->right);

	if (leftH > rightH)
		height = leftH + 1;
	else
		height = rightH + 1;

	return (height);
}

/**
 * binary_tree_height - find the height of a binary tree
 * @tree: a pointer to the tree
 * Return: the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height;

	height = binary_tree_height2(tree);
	if (height == 0)
		return (0);
	return (height - 1);
}
