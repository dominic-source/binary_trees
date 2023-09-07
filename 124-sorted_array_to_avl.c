#include "binary_trees.h"
/**
 * recursion - insert node in a binary search tree
 * @parent: the parent node
 * @start: the start index of the array
 * @end: the end index of the array
 * @array: array of integers
 * Return: Node  or NULL
 */
avl_t *recursion(avl_t *parent, size_t start, size_t end, int *array)
{
	avl_t *node;
	size_t mid;

	if (start >= end)
		return (NULL);

	mid = (end + start) / 2;
	node = (avl_t *)binary_tree_node((binary_tree_t *)parent, array[mid]);

	if (node == NULL)
		return (NULL);

	node->left = recursion(node, start, mid - 1, array);
	node->right = recursion(node, mid + 1, end, array);

	return (node);
}
/**
 * sorted_array_to_avl - create an avl tree from a sorted array
 * @array: a pointer to the array
 * @size: the size of the array
 * Return: NULL or pointer to the root of the tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (recursion(NULL, 0, size - 1, array));
}
