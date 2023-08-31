#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate binary tree left
 * @tree: a pointer to the tree
 * Return: a pointer to the new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *current, *right;

	if (tree == NULL)
		return (NULL);

	current = tree->left;
	tree->parent = current;
	if (current->right != NULL)
		right = current->right;
	else
		right = NULL;
	current->right = tree;
	tree->left = right;
	current->parent = NULL;
	return (current);
}
