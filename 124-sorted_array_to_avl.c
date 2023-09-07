#include "binary_trees.h"
/**
 * recursion - insert node in a binary search tree
 * @parent: the parent node
 * @start: the start index of the array
 * @end: the end index of the array
 * @array: array of integers
 * Return: Node  or NULL
 */
binary_tree_t *recursion(binary_tree_t *parent, int start,
			 int end, int *array)
{
	binary_tree_t *node;
	size_t mid;

	if (start > end || end < 0 || start < 0)
		return (NULL);

	mid = (start + end) / 2;
	node = binary_tree_node(parent, array[mid]);

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
	binary_tree_t *node;

	if (array == NULL || size == 0)
		return (NULL);
	node = recursion(NULL, 0, (int)(size - 1), array);
	return ((avl_t *)node);
}
