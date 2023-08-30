#include "binary_trees.h"
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
unsigned char is_leaf(const binary_tree_t *node);
int is_perfect(const binary_tree_t *tree,
						 size_t leaf_depth, size_t level);

/**
 * depth - node in a binary tree depth
 * @tree: Pointer to the node to measure the depth
 *
 * Return: Node depth
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Returns a leaf pointer
 * @tree: Pointer to the root node
 *
 * Return: leaf pointer
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_leaf - Is node a leaf
 * @node: Pointer to the node
 *
 * Return:  NULL, 0 or 1
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	if (node->left == NULL && node->right == NULL)
		return (1);
	else
		return (0);
}

/**
 * is_perfect - Is binary tree perfect
 * @tree: Pointer to the root node
 * @leaf_depth: Leaf depth
 * @level: Current node level
 *
 * Return: NULL, 0 or 1
 */
int is_perfect(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
	{
		if (level == leaf_depth)
			return (1);
		else
			return (0);
	}
	if (!tree->left || !tree->right)
		return (0);
	return (is_perfect(tree->left, leaf_depth, level + 1) &&
			is_perfect(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: NULL, 0 or 1
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree != NULL)
		return (is_perfect(tree, depth(get_leaf(tree)), 0));
	return (0);
}
