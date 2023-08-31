#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate binary tree right
 * @tree: a pointer to the tree
 * Return: a pointer to the new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *current, *right;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	current = tree->left;
	tree->parent = current;

	right = current->right;

	current->right = tree;
	tree->left = right;
	current->parent = NULL;
	if (right != NULL)
		right->parent = tree;
	return (current);
}
