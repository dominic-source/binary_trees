#include "binary_trees.h"

/**
 * binary_tree_height - find the height of a binary tree
 * @tree: a pointer to the tree
 * Return: the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	if (tree == NULL)
		return (0);
	while (tree != NULL)
	{
		if (tree->left != NULL)
		{
			tree = tree->left;
			height += 1;
		}
		else if (tree->right != NULL)
		{
			tree = tree->right;
			height += 1;
		}
		else
			tree = NULL;
	}
	return (height);
}
