#include "binary_trees.h"

int tree_rem(const binary_tree_t *tree);
int level_height(const binary_tree_t *tree);
int level_check(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (level_check(tree, INT_MIN, INT_MAX));
}


/**
 * level_check - Level checker
 * @tree: pointer to root
 * @min: min value
 * @max: max value
 *
 * Return: 1 or 0
 */
int level_check(const binary_tree_t *tree, int min, int max)
{
	int rem_left, rem_right, rem;

	if (tree == NULL)
		return (1);
	if (tree->n > max || tree->n < min)
		return (0);
	rem = tree_rem(tree);
	if (rem < -1 || rem > 1)
		return (0);
	rem_left = level_check(tree->left, min, tree->n - 1);
	rem_right = level_check(tree->right, tree->n + 1, max);
	if (rem_left == 1 && rem_right == 1)
		return (1);
	return (0);
}

/**
 * tree_rem - factor calculate
 * @tree: pointer to root
 *
 * Return: rem
 */
int tree_rem(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (level_height(tree->left) - level_height(tree->right));
}

/**
 * level_height - auxiliary level
 * @tree: pointer to root
 *
 * Return: Level
 */
int level_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	left_height = level_height(tree->left);
	right_height = level_height(tree->right);
	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}
