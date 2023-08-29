#include "binary_trees.h"

/**
 * bst_minimum - find the minimum value of a node
 *
 * @node: the parent node
 *
 * Return: a pointer tothe minimum value
 */
binary_tree_t *bst_minimum(binary_tree_t *node)
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
binary_tree_t *bst_successor(binary_tree_t *node)
{
	if (node->right != NULL)
		return (bst_minimum(node));

}

/**
 * binary_tree_delete - delete binary tree starting from the root
 *
 * @tree: a pointer to the root node of the tree to delete
 *
 * Return: Nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *current;

	if (tree == NULL)
		return;

