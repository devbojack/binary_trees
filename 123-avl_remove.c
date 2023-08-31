#include "binary_trees.h"

void rem(avl_t **tree);
int par(bst_t *node);
int remove_type(bst_t *root);
bst_t *bst_remove(bst_t *root, int value);

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 *
 * Return: tree pointer
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *)bst_remove((bst_t *)root, value);

	if (root_a == NULL)
		return (NULL);
	rem(&root_a);
	return (root_a);
}

/**
 * rem - Measures balance factor of a AVL
 * @tree: tree
 *
 * Return: rem factor
 */
void rem(avl_t **tree)
{
	int re;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	rem(&(*tree)->left);
	rem(&(*tree)->right);
	re = binary_tree_balance((const binary_tree_t *)*tree);
	if (re > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (re < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * bst_remove - remove node from a BST tree
 * @root: root node
 * @value: value node
 *
 * Return: tree pointer
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root != NULL)
	{
		if (value < root->n)
			bst_remove(root->left, value);
		else if (value > root->n)
			bst_remove(root->right, value);
		else if (value == root->n)
		{
			type = remove_type(root);
			if (type != 0)
				bst_remove(root->right, type);
		}
		else
			return (NULL);

		return (root);
	}

	return (NULL);
}

/**
 * par - get next
 * @node: tree to check
 *
 * Return: the min value of this tree
 */
int par(bst_t *node)
{
	int left = 0;

	if (node != NULL)
	{
		left = par(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
	return (0);
}

/**
 * remove_type - Removes a node type
 * @root: node pointer
 *
 * Return: 0 or pointer
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = par(root->right);
		root->n = new_value;
		return (new_value);
	}
}
