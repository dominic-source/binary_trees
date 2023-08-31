#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate binary tree left
 * @tree: a pointer to the tree
 * Return: a pointer to the new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *current, *left;

	if (tree == NULL)
		return (NULL);
	current = tree->right;
	tree->parent = current;
	if (current->left != NULL)
		left = current->left;
	else
		left = NULL;
	current->left = tree;
	tree->right = left;
	current->parent = NULL;
	return (current);
}
