#include "binary_trees.h"
/**
 * insert - insert node in a binary search tree
 * @tree: a double pointer to the root node
 * @value: the value the node
 * Return: a pointer to the created  node
 */
avl_t *insert(avl_t **tree, int value)
{
        avl_t *node, *y, *x = *tree;

        y = NULL;

        node = (avl_t *)binary_tree_node(NULL, value);
        while (x != NULL)
        {
                y = x;
                if (node->n < x->n)
                        x = x->left;
                else if (node->n == x->n)
                {
                        free(node);
                        return (y);
                }
                else if (node->n > x->n)
                        x = x->right;
        }
        node->parent = y;
        if (y == NULL)
                *tree = node;
        else if (node->n < y->n)
                y->left = node;
        else
                y->right = node;
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
	avl_t *node, *tree;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	tree = NULL;
	for (i = 0; i < size; i++)
	{
		node = insert(&tree, array[i]);
		if (node == NULL)
			return (NULL);
	}
	return (tree);
}
