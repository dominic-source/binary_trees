#include "binary_trees.h"

/**
 * balance_avl - balances avl binary search tree
 * @tree: a pointer to the root
 * @node: the child that was inserted
 * Return: Nothing
 */
void balance_avl(avl_t **tree, avl_t *node)
{
	avl_t *x, *new;
	int bfx;

	for (x = node->parent; x != NULL; x = x->parent)
	{
		bfx = binary_tree_balance(x);

		if (bfx > 1)
		{
			if (node->n < x->left->n)
				new = binary_tree_rotate_right(x);
			else
			{
				x->left = binary_tree_rotate_left(x->left);
				new = binary_tree_rotate_right(x);
			}
		}
		else if (bfx < -1)
		{
			if (node->n > x->right->n)
				new = binary_tree_rotate_left(x);
			else
			{
				x->right = binary_tree_rotate_right(x->right);
				new = binary_tree_rotate_left(x);
			}
		}
		else
			new = x;

		if (new->parent != NULL)
		{
			if (new->n < new->parent->n)
				new->parent->left = new;
			else
				new->parent->right = new;
		}
		else
			*tree = new;
	}
}

/**
 * avl_insert - insert value in an avl tree
 * @tree: a pointer to the tree node
 * @value: the value of the node
 * Return: NULL or pointer to the created node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node, *current, *hold = NULL;

	node = (avl_t *)binary_tree_node(NULL, value);
	if (node == NULL)
		return (NULL);
	current = *tree;
	while (current != NULL)
	{
		hold = current;
		if (current->n > value)
			current = current->left;
		else if (current->n == value)
		{
			free(node);
			return (current);
		}
		else
			current = current->right;
	}
	node->parent = hold;
	if (hold == NULL)
		*tree = node;
	else if (hold->n > value)
		hold->left = node;
	else
		hold->right = node;
	balance_avl(tree, node);
	return (node);
}
