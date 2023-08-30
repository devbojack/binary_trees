#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf_count = 0;

	if (tree != NULL)
	{
		if (!tree->left && !tree->right)
			leaf_count++;
		leaf_count += binary_tree_leaves(tree->left);
		leaf_count += binary_tree_leaves(tree->right);
	}
	return (leaf_count);
}
