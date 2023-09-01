#include "binary_trees.h"

/**
 * array_to_bst - convert array to a binary search tree
 * @array: the array of integers
 * @size: the size of the array
 * Return: NULL or pointer to the root node
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root;
	size_t i;

	root = NULL;
	if (array == NULL || size == 0)
		return (NULL);
	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);
	return (root);
}
