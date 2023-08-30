#include "binary_trees.h"

int count_nodes(binary_tree_t *root);
int is_complete(binary_tree_t *root, int index, int count);

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: Root node pointer
 *
 * Return: 1 or 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int the_node;
	binary_tree_t *root;

	if (tree != NULL)
	{
		root = (binary_tree_t *)tree;
		the_node = count_nodes(root);

		return (is_complete(root, 0, the_node));

	}
	return (0);
}

/**
 * count_nodes - Node counter
 * @root: root node
 *
 * Return: nodes count
 */
int count_nodes(binary_tree_t *root)
{
	if (root != NULL)
		return (1 + count_nodes(root->left) + count_nodes(root->right));
	return (0);
}

/**
 * is_complete - Checks if is complete
 * @root: Root pointer
 * @index: node index
 * @count: node count
 *
 * Return: 1 or 0
 */
int is_complete(binary_tree_t *root, int index, int count)
{
	if (root != NULL)
	{
		if (index >= count)
			return (0);
		if (!root->left && !root->right)
			return (1);
		if (root->right && !root->left)
			return (0);
		if (root->left && !root->right)
			return (is_complete(root->left, index * 2 + 1, count));

		return (is_complete(root->left, index * 2 + 1, count) &&
			is_complete(root->right, index * 2 + 2, count));
	}

	return (0);
}

