#include "binary_trees.h"

/**
 * binary_tree_preorder - traverse through a binary tree
 * @tree: the tree node
 * @func: the print function
 * Return: Nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
