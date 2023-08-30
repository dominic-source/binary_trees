#include "binary_trees.h"
/**
 * binary_height - finds the height of the tree
 * @tree: a pointer to the tree
 *
 * Return: height or -1
 */
int binary_height(const binary_tree_t *tree)
{
	int leftH, rightH, height;

	if (tree == NULL)
		return (-1);
	leftH = binary_height(tree->left);
	rightH = binary_height(tree->right);
	if (leftH > rightH)
		height = leftH + 1;
	else
		height = rightH + 1;
	return (height);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the tree
 *
 * Return: 0 or 1
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int right, left;

	if (tree == NULL)
		return (0);
	if (tree->right == NULL && tree->left == NULL)
		return (1);
	right = binary_height(tree->right);
	left = binary_height(tree->left);
	if (right == left)
		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	return (0);
}
