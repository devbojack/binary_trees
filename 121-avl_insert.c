#include "binary_trees.h"

avl_t *avl_insert_full(avl_t *tree, avl_t *parent, int value);
void rem_val(avl_t **root, avl_t *tree, int value);

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree for inserting the value
 * @value: value to store in the node to be inserted
 *
 * Return: New node pointer
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node;
	avl_t *predecessor;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}
	new_node = avl_insert_full(*tree, NULL, value);

	if (new_node == NULL)
		return (NULL);

	predecessor = new_node->parent;

	while (predecessor != NULL)
	{
		rem_val(tree, predecessor, value);
		predecessor = predecessor->parent;
	}

	return (new_node);
}

/**
 * avl_insert_full - Inserts a value in an AVL Tree
 * @tree: Root node pointer
 * @parent: Node parent
 * @value: value to store in the node to be inserted
 * Return: pointer to the new_node node
 */
avl_t *avl_insert_full(avl_t *tree, avl_t *parent, int value)
{
	avl_t *new_node;

	if (tree == NULL)
	{
		new_node = binary_tree_node(parent, value);
		if (parent->n > new_node->n)
			parent->left = new_node;
		else
			parent->right = new_node;
		return (new_node);
	}
	else if (value == tree->n)
		return (NULL);
	else if (value < tree->n)
		return (avl_insert_full(tree->left, tree, value));
	else
		return (avl_insert_full(tree->right, tree, value));
}

/**
 * rem_val - rem or node
 * @root: Root pointer
 * @tree: The tree
 * @value: Value
 *
 * Return: 0
 */
void rem_val(avl_t **root, avl_t *tree, int value)
{
	int new_balance;

	new_balance = binary_tree_balance(tree);
	if (new_balance > 1)
	{
		if (tree->left->n > value)
		{
			if (*root == tree)
				*root = tree->left;
			binary_tree_rotate_right(tree);
		}
		else
		{
			if (*root == tree)
				*root = tree->left->right;
			binary_tree_rotate_left(tree->left);
			binary_tree_rotate_right(tree);
		}
	}
	if (new_balance < -1)
	{
		if (tree->right->n < value)
		{
			if (*root == tree)
				*root = tree->right;
			binary_tree_rotate_left(tree);
		}
		else
		{
			if (*root == tree)
				*root = tree->right->left;
			binary_tree_rotate_right(tree->right);
			binary_tree_rotate_left(tree);
		}
	}
}
