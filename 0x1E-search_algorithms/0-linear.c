#include <stdio.h>
#include "search_algos.h"

/**
 * linear_search - this searches for a value using Ls i an array
 * @array: pOinter to array to search
 * @size: size of the array to search
 * @value: value to search
 * Return: 1st index where value is located and -1 if none
 */

int linear_search(int *array, size_t size, int value)
{
	size_t k;

	if (array == NULL)
		return (-1);

	for (k = 0; k < size; k++)
	{
		printf("Value checked array[%lu] = [%d]\n", k, array[k]);
		if (array[k] == value)
			return (k);
	}
	return (-1);
}
