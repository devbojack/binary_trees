#include "binary_trees.h"

bst_t *find_minimum(bst_t *root);

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: Pointer or NULL
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp;
	bst_t *parent;

	if (root == NULL)
		return (NULL);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			tmp = root;
			parent = root->parent;
			root = root->right;
			root->parent = parent;
			free(tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root;
			parent = root->parent;
			root = root->left;
			root->parent = parent;
			free(tmp);
		}
		else
		{
			tmp = find_minimum(root->right);
			root->n = tmp->n;
			root->right = bst_remove(root->right, tmp->n);
		}
	}
	return (root);
}

/**
 * find_minimum - Finds the minimum root
 * @root: pointer to the tree
 *
 * Return: minimum number
 */
bst_t *find_minimum(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
