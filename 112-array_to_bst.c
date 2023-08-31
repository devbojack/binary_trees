#include "binary_trees.h"

/**
 * array_to_bst - Function that builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: Pointer or null
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t length;

	for (length = 0; length < size; length++)
		bst_insert(&tree, array[length]);

	return (tree);
}
