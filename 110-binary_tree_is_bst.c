#include "binary_trees.h"

int is_best(const binary_tree_t *tree_node, int min, int max);

/**
 * binary_tree_is_bst - checks if a binary tree is a
 * valid Binary Search tree
 * @tree: Root node pointer
 *
 * Return: 1 or 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree != NULL)
		return (is_best(tree, INT_MIN, INT_MAX));

	return (0);
}

/**
 * is_best - Is best
 * @tree_node: Root node
 * @min: Min value
 * @max: Max value
 *
 * Return: 1 or 0
 */
int is_best(const binary_tree_t *tree_node, int min, int max)
{
	if (tree_node == NULL)
		return (1);

	if (tree_node->n < min || tree_node->n > max)
		return (0);

	return (
		is_best(tree_node->left, min, tree_node->n - 1) &&
		is_best(tree_node->right, tree_node->n + 1, max));
}
