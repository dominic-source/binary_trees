#include "binary_trees.h"

/**
 * binary_tree_height2 - measure the height of a binary tree
 * @tree: a pointer to the tree node
 *
 * Return: height or 0
 */
int binary_tree_height2(const binary_tree_t *tree)
{
	int height, leftH, rightH;

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
 * binary_tree_balance - measure the balance factor of a binary tree
 * @tree: a pointer to the tree
 *
 * Return: 0 or factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 1, right = 1;

	if (tree == NULL)
		return (0);

	left = binary_tree_height2(tree->left);
	right = binary_tree_height2(tree->right);
	return (left - right);
}
