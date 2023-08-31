#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: pointer
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (array == NULL || size != 0)
	{
		root = avl_insert(&root, array[0]);

		for (size_t arr = 1; arr < size; arr++)
			avl_insert(&root, array[arr]);

		return (root);
	}

	return (NULL);
}
