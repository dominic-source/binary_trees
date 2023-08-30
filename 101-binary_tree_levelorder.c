#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverse the tree and print it value in levelorder
 * @tree: a pointer to the tree
 * @func: a function to print
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	binary_tree_t *current;
	int front = 0, rear = 0;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(binary_tree_t *) * 1000);
	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		current = queue[front++];
		func(current->n);

		if (current->left != NULL)
			queue[rear++] = current->left;
		if (current->right != NULL)
			queue[rear++] = current->right;
	}
	free(queue);
}
