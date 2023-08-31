#include "binary_trees.h"
/**
 * binary_size - finds the size of the tree
 * @tree: a pointer to the tree
 *
 * Return: size or 0
 */
int binary_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_size(tree->left) + binary_size(tree->right));
}


/**
 * binary_recursion - check if a tree is complete
 * @index: the index of the node
 * @size: the size of the node
 * @tree: a pointer to the tree
 *
 * Return: 0 or 1
 */
int binary_recursion(const binary_tree_t *tree, int index, int size)
{
	if (tree == NULL)
		return (1);
	if (index >= size)
		return (0);
	return (binary_recursion(tree->left, (2 * index) + 1, size) &&
			binary_recursion(tree->right, (2 * index) + 2, size));
}


/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the tree
 *
 * Return: 0 or 1
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_recursion(tree, 0, binary_size(tree)));
}
