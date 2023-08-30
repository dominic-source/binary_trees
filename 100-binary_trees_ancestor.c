#include "binary_trees.h"

/**
 * binary_depth - find the depth of the binary tree
 * @tree: a pointer to the tree
 *
 * Return: 0 or depth
 */
size_t binary_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent != NULL)
	{
		depth += 1;
		tree = tree->parent;
	}
	return (depth);
}


/**
 * binary_trees_ancestor - find the lowest common ancestor
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: a pointer to the ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t first_d, second_d, iter = 0, i;

	first_d = binary_depth(first);
	second_d = binary_depth(second);

	if (first_d < second_d)
	{
		iter = second_d - first_d;
		for (i = 0; i < iter; i++)
			second = second->parent;
	}
	else if (first_d > second_d)
	{
		iter = first_d - second_d;
		for (i = 0; i < iter; i++)
			first = first->parent;
	}
	while (first != second && first != NULL && second != NULL)
	{
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}
