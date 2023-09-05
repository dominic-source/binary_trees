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
	left = current->left;

	current->parent = tree->parent;
	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = current;
		else
			tree->parent->right = current;
	}
	tree->right = left;
	if (left != NULL)
		left->parent = tree;
	tree->parent = current;
	current->left = tree;

	return (current);
}
