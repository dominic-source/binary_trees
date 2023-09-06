#include "binary_trees.h"

/**
 * array_to_avl - build an avl tree from an array
 * @array: a pointer to an array of integers
 * @size: the size of the array
 * Return: NULL or a pointer to the root node of the tree
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree, *node;
	size_t i;

	tree = NULL;
	if (array == NULL || size == 0)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		node = avl_insert(&tree, array[i]);
		if (node == NULL)
			return (NULL);
	}

	return (tree);
}
