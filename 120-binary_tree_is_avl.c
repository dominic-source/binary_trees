#include "binary_trees.h"

/**
 * bin_height - checks the height of a binary tree
 * @tree: a pointer to the root node
 * Return: height or 0
 */
int bin_height(const binary_tree_t *tree)
{
	int leftH, rightH, height = 0;

	if (tree == NULL)
		return (0);

	leftH = bin_height(tree->left);
	rightH = bin_height(tree->right);

	if (leftH > rightH)
		height = 1 + leftH;
	else
		height = 1 + rightH;
	return (height);
}


/**
 * bin_recursion - checks if the tree is a bst
 * @tree: a pointer to the root node
 * @min: the minimum value of a subtree
 * @max: the maximum value of a subtree
 * Return: 0 or 1
 */
int bin_recursion(const binary_tree_t *tree,
		const binary_tree_t *min, const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);
	if ((min && min->n >= tree->n) || (max && max->n <= tree->n))
		return (0);

	return (bin_recursion(tree->left, min, tree) &&
			bin_recursion(tree->right, tree, max));
}

/**
 * binary_tree_is_avl2 - this will check if a tree is avl
 * @tree: a pointer to the tree
 * Return: 0 0r 1
 */
int binary_tree_is_avl2(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (1);
	height = bin_height(tree->left) - bin_height(tree->right);
	if (height < -1 || height > 1)
		return (0);
	return (binary_tree_is_avl2(tree->left) && binary_tree_is_avl2(tree->right));
}

/**
 * binary_tree_is_avl - this will check if a tree is avl
 * @tree: a pointer to the tree
 * Return: 0 0r 1
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_is_avl2(tree) && bin_recursion(tree, NULL, NULL));
}
