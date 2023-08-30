#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
void level_order(const binary_tree_t *tree, int level, void (*func)(int));

/**
 * binary_tree_levelorder - Level-order traversal
 * @tree: Root node pointer
 * @func: Function pointer to call
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = 0;
	int len = 1;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree) + 1;

	while (len <= height)
	{
		level_order(tree, len, func);
		len++;
	}
}

/**
 * binary_tree_height - Binary tree heighter
 * @tree: tree pointer
 *
 * Return: 0 or pointer
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
    size_t right_height = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height);
    else
	    return (right_height);
}

/**
 * level_order - print each
 * @tree: pointer to thse
 * @level: level of the tree
 * @func: pointer to a  node
 *
 * Return: void
 */

void level_order(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		level_order(tree->left, level - 1, func);
		level_order(tree->right, level - 1, func);
	}
}
