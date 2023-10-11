#include <stdio.h>
#include "search_algos.h"
/**
 * binary_search2 - searches vaalue ina array using BS
 * @array: pointer to the array bbeing searched
 * @left: its beginning of an array
 * @right: end of an array
 * @value: value searched for
 * Return: index where the vslue is created
 */
int binary_search2(int *array, size_t left, size_t right, int value)
{
	size_t k;

	if (array == NULL)
		return (-1);

	while (left <= right)
	{
		printf("Searching in array: ");
		for (k = left; k < right; k++)
			printf("%d, ", array[k]);
		printf("%d\n", array[k]);

		k = left + (right - left) / 2;
		if (array[k] == value)
			return (k);
		if (array[k] > value)
			right = k - 1;
		else
			left = k + 1;
	}
	return (-1);
}

/**
 * exponential_search - searches value using ES
 * @array: array to search
 * @size: size of array being searched
 * @value: value to search in the array
 * Return: 1st index where the value is located
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t b = 0, right;

	if (array == NULL)
		return (-1);
	if (array[0] != value)
	{
		for (b = 1; b < size && array[b] <= value; b = b * 2)
			printf("Value checked array[%ld] = [%d]\n", b, array[b]);
	}
	right = b < size ? b : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", b / 2, right);
	/*
	 * dividing b by 2 finds the midpoint
	 */
	return (binary_search2(array, b / 2, right, value));
}
