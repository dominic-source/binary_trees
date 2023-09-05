#include "binary_trees.h"

/**
 * balance_avl - balances avl binary search tree
 * @tree: a pointer to the root
 * @node: the child that was inserted
 * Return: Nothing
 */
void balance_avl(avl_t **tree, avl_t *node)
{
	avl_t *x, *g, *new;
	int bfx = 0, bfz = 0;

	for (x = node->parent; x != NULL; x = x->parent)
	{
		bfz = binary_tree_balance(node);
		bfx = binary_tree_balance(x);
		if (node == x->right)
		{
			if (bfx > 0)
			{
				g = x->parent;
				if (bfz < 0)
				{
					new = binary_tree_rotate_right(node);
					new = binary_tree_rotate_left(x);
				}
				else
					new = binary_tree_rotate_left(x);
			}
			else
			{
				if (bfx < 0)
				{
					bfx = 0;
					break;
				}
				bfx = 1;
				node = x;
				continue;
			}
		}
		else
		{
			if (bfx < 0)
			{
				g = x->parent;
				if (bfz > 0)
				{
					new = binary_tree_rotate_left(node);
					new = binary_tree_rotate_right(x);
				}
				else
					new = binary_tree_rotate_right(x);
			}
			else
			{
				if (bfx > 0)
				{
					bfx = 0;
					break;
				}
				bfx = -1;
				node = x;
				continue;
			}
		}
		new->parent = g;
		if (g != NULL)
		{
			if (x == g->left)
				g->left = new;
			else
				g->right = new;
		}
		else
			*tree = new;
		break;
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
			return (NULL);
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
