#include "binary_trees.h"

/**
 * bst_search - search for a value in the bst
 * @tree: a pointer to the binary tree
 * @value: the value to search for
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	while (tree != NULL)
	{
		if (tree < value)
			tree = tree->right;
		else if (tree > value)
			tree = tree->left;
		else
			return (tree);
	}
	return (NULL);
}
