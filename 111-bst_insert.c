#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: NULL or pointer
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;
	bst_t *rev_tree;

	if (tree == NULL || *tree == NULL)
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
		return (new);
	}

	rev_tree = *tree;

	while (rev_tree != NULL)
	{
		if (rev_tree->n == value)
			return (NULL);
		if (rev_tree->n > value)
		{
			if (rev_tree->left == NULL)
			{
				rev_tree->left = binary_tree_node(rev_tree, value);
				return (rev_tree->left);
			}
			rev_tree = rev_tree->left;
		}
		if (rev_tree->n < value)
		{
			if (rev_tree->right == NULL)
			{
				rev_tree->right = binary_tree_node(rev_tree, value);
				return (rev_tree->right);
			}
			rev_tree = rev_tree->right;
		}
	}
	return (NULL);
}
