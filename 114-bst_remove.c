#include "binary_trees.h"

/**
 * bst_minimum - find the minimum value of a node
 *
 * @node: the parent node
 *
 * Return: a pointer tothe minimum value
 */
bst_t *bst_minimum(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_successor - find the successor of a node
 *
 * @node: the pointer to the node
 *
 * Return: a pointer to the successor
 */
bst_t *bst_successor(bst_t *node)
{
	bst_t *hold;

	if (node->right != NULL)
		return (bst_minimum(node->right));
	hold = node->parent;

	while (hold != NULL && node == hold->right)
	{
		node = hold;
		hold = hold->parent;
	}
	return (hold);
}

/**
 * shift_node - shift node
 * @u: node to replace
 * @v: the replacement node
 * Return: Nothing
 */
bst_t *shift_node(bst_t *u, bst_t *v)
{
	if (u->parent == NULL)
	{
		if (v != NULL)
			v->parent = u->parent;
		return (v);
	}
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v != NULL)
		v->parent = u->parent;
	return (NULL);
}

/**
 * bst_search - search for a value in the bst
 * @tree: a pointer to the binary tree
 * @value: the value to search for
 * Return: a pointer to the node or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	while (tree != NULL)
	{
		if (tree->n < value)
			tree = tree->right;
		else if (tree->n > value)
			tree = tree->left;
		else
			return ((bst_t *)tree);
	}
	return (NULL);
}

/**
 * bst_remove - remove binary tree starting from the root
 *
 * @tree: a pointer to the root node of the tree to remove
 * @value: the value of the node to remove
 * Return: New root node
 */
bst_t *bst_remove(bst_t *tree, int value)
{
	bst_t *current, *rem, *ntree = NULL;

	rem = bst_search((const bst_t *)tree, value);
	if (tree == NULL || rem == NULL)
		return (NULL);
	if (rem->left == NULL)
	{
		ntree = shift_node(rem, rem->right);
		free(rem);
		if (ntree == NULL)
			return (tree);
		else
			return (ntree);
	}
	else if (rem->right == NULL)
	{
		ntree = shift_node(rem, rem->left);
		free(rem);
		if (ntree == NULL)
			return (tree);
		else
			return (ntree);
	}
	else
	{
		current = bst_successor(rem);
		if (current->parent != rem)
		{
			ntree = shift_node(current, current->right);
			current->right = rem->right;
			current->right->parent = current;
		}
		tree = ntree != NULL ? ntree : tree;
		ntree = shift_node(rem, current);
		current->left = rem->left;
		current->left->parent = current;
		free(rem);
		if (ntree == NULL)
			return (tree);
		else
			return (ntree);
	}
	return (tree);
}
