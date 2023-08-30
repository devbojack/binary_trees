#include "binary_trees.h"

/**
 * b_t_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 0 if tree is NULL
 */
size_t b_t_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree)
	{
		left = (tree->left) ? 1 + b_t_height(tree->left) : 1;

		right = (tree->right) ? 1 + b_t_height(tree->right) : 1;

		if (left > right)
			return (left);
		else
			return (right);
	}
	return (0);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (b_t_height(tree->left) - b_t_height(tree->right));
	}
	return (0);
}
