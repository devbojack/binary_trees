#include "binary_trees.h"

int bt_is_perfect(const binary_tree_t *tree);
int t_is_perfect(const binary_tree_t *tree);
int bt_rem(const binary_tree_t *tree);
size_t bt_height(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - Valid Max Binary Heap checker
 * @tree: tree to check
 *
 * Return: 1 or 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int rem;

	if (tree != NULL)
	{
		if ((tree->left && tree->left->n > tree->n) || (tree->right && tree->right->n > tree->n))
			return (0);
		if (bt_is_perfect(tree))
			return (1);
		rem = bt_rem(tree);

		if (rem == 0)
		{
			return (bt_is_perfect(tree->left) &&
				binary_tree_is_heap(tree->right));
		}
		if (rem == 1)
		{
			return (binary_tree_is_heap(tree->left) &&
				bt_is_perfect(tree->right));
		}
		else
			return (0);
	}
	return (0);
}

/**
 * bt_is_perfect - Is perfect check
 * @tree: tree pointer
 *
 * Return: 1 or 0
 */
int bt_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree != NULL)
	{
		result = t_is_perfect(tree);

		if (result != 0)
			return (1);

		return (0);
	}
	return (0);
}


/**
 * t_is_perfect - Tree is perfect check
 * @tree: tree pointer
 *
 * Return: 0 or int
 */
int t_is_perfect(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (tree->left && tree->right)
	{
		left = 1 + t_is_perfect(tree->left);
		right = 1 + t_is_perfect(tree->right);

		if (right == left && right != 0 && left != 0)
			return (right);

		return (0);
	}
	else if (!tree->left && !tree->right)
		return (1);
	else
		return (0);
}


/**
 * bt_rem - Binary tree rem
 * @tree: tree pointer
 *
 * Return: int
 */
int bt_rem(const binary_tree_t *tree)
{
	int right = 0;
	int left = 0;
	int total = 0;

	if (tree != NULL)
	{
		left = ((int)bt_height(tree->left));
		right = ((int)bt_height(tree->right));
		total = left - right;
	}
	return (total);
}

/**
 * bt_height - Height
 * @tree: tree pointer
 *
 * Return: the height
 */
size_t bt_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree != NULL)
	{
		if (tree->left == NULL && tree->right == NULL)
			return (tree->parent != NULL);
		if (tree)
		{
			left = tree->left ? 1 + bt_height(tree->left) : 0;
			right = tree->right ? 1 + bt_height(tree->right) : 0;
		}
		if (left > right)
			return (left);
		else
			return (right);
	}
	return (0);
}
