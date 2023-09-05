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
	right = current->right;

	tree->left = right;
	current->parent = tree->parent;

	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = current;
		else
			tree->parent->right = current;
	}
	if (right != NULL)
		right->parent = tree;

	tree->parent = current;
	current->right = tree;
	return (current);
}
