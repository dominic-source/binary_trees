#include "binary_trees.h"

/**
 * binary_tree_inorder - traverse through the tree inorder
 * @tree: the pointer to the tree node
 * @func: a pointer to a function
 * Return: 1 or 0
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
