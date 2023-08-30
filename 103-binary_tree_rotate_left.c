#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation
 * @tree: Root pointer
 *
 * Return: Null or root pointer
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *ch;
	binary_tree_t *parent = tree;

	if (tree != NULL)
	{
		ch = parent->right;
		if (ch == NULL)
			return (tree);

		if (ch->left)
			ch->left->parent = parent;

		parent->right = ch->left;
		ch->left = parent;
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
