#include "search_algos.h"
#include <stdio.h>

/**
 * interpolation_search - searches value sorted array and use IS
 * @array: array to search
 * @size: size of the array
 * @value: value to search fot in the array
 * Return: 1st index where value is located
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t k;
	size_t i = 0;
	size_t me = size - 1;

	if (array == NULL)
		return (-1);
	while (i <= me)
	{
		k = i + (((double)(me - i) / (array[me] - array[i])) * (value - array[i]));
		if (k < size)
			printf("Value checked array[%ld] = [%d]\n", k, array[k]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", k);
			break;
		}
		if (array[k] == value)
			return (k);
		if (array[k] > value)
			me = (k - 1);
		else
			i = (k + 1);
	}
	return (-1);
}
