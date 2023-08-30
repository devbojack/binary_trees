#include "binary_trees.h"

/**
 * binary_tree_rotate_right -  performs a right-rotation
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: Pointer or NULL
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *ch, *parent = tree;

	if (tree != NULL)
	{
		ch = parent->left;
		if (ch == NULL)
			return (tree);

		if (ch->right)
			ch->right->parent = parent;

		parent->left = ch->right;
		ch->right = parent;
		ch->parent = parent->parent;
		parent->parent = ch;

		if (ch->parent && ch->parent->left == parent)
			ch->parent->left = ch;
		else if (ch->parent)
			ch->parent->right = ch;

		return (ch);
	}

	return (NULL);
}
