#include "binary_trees.h"

/**
 * binary_recursion - recursively check for bst
 * @tree: a pointer to the tree
 * @max: the maximum value node
 * @min: the minimum value node
 * Return: 1 or 0
 */
int binary_recursion(const binary_tree_t *tree,
		     const binary_tree_t *min, const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);
	if ((min && tree->n <= min->n) || (max && tree->n >= max->n))
		return (0);
	return (binary_recursion(tree->left, min, tree) &&
		binary_recursion(tree->right, tree, max));
}

/**
 * binary_tree_is_bst - check if a binary tree is a binary search tree
 * @tree: a pointer to the tree
 * Return: 1 or 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_recursion(tree, NULL, NULL));
}
