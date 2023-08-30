#include "binary_trees.h"

/**
 * full_tree -Is binary full checker
 * @tree: Root pointer
 *
 * Return: 0 or 1
 */
int full_tree(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left && tree->right) ||
				(tree->left && tree->right) ||
			full_tree(tree->left) == 0 ||
			full_tree(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: NULL, 0 or -1
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (full_tree(tree));
}
