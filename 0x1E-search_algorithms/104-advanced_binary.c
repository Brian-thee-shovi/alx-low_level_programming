#include <stdio.h>
#include "search_algos.h"
/**
 * advanced_binary_recursive - searches for value recursively
 * @array: array to search
 * @left: begining of an array
 * @right: end of an array
 * @value: value of an array to search
 * Return: index of the found value, -1 if not found
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t k;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (k = left; k < right; k++)
		printf("%d,", array[k]);
	printf("%d\n", array[k]);

	k = left + (right - left) / 2;
	if (array[k] == value && (k == left || array[k - 1] != value))
		return (k);
	if (array[k] >= value)
		return (advanced_binary_recursive(array, left, k, value));
	return (advanced_binary_recursive(array, k + 1, right, value));
}

/**
 * advanced_binary - searches value in a sorted arr of ints
 * @array: array to search for the value
 * @size: size of the array being searched
 * @value: value beign searched for
 * Return: index of the searched value
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (advanced_binary_recursive(array, 0, size - 1, value));
}
