#include "binary_trees.h"

avl_t *rem_sorted_array_to_avl(int *array, int first_index,
									 int final_index);
/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: pointer or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size < 1)
		return (NULL);
	return (rem_sorted_array_to_avl(array, 0, size - 1));
}

/**
 * rem_sorted_array_to_avl - recursive array to avl
 * @array: pointer to array
 * @first_index: sub array initial index
 * @last_index: final index
 *
 * Return: pointer to root
 */
avl_t *rem_sorted_array_to_avl(int *array, int first_index,
									 int last_index)
{
	avl_t *root;
	int half;

	if (last_index < first_index)
		return (NULL);

	half = (last_index + first_index) / 2;
	root = binary_tree_node(NULL, array[half]);

	if (root != NULL)
	{
		root->left = rem_sorted_array_to_avl(array, first_index, half - 1);
		root->right = rem_sorted_array_to_avl(array, half + 1, last_index);

		if (root->left)
			root->left->parent = root;
		if (root->right)
			root->right->parent = root;

		return (root);
	}
	return (NULL);
}
