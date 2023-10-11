#include <stdio.h>
#include "search_algos.h"
/**
 * print_array - this prints subarray everytime it is  searched
 * @array: pointer to the array being searched
 * @start: beginning of an array
 * @end: end of an array
 * Return: nothing
 */

void print_array(int *array, size_t start, size_t end)
{
	size_t k;

	printf("Searching in array: ");

	for (k = start; k <= end; k++)
	{
		printf("%d", array[k]);
		if (k < end)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search - searches for value in an array using bs
 * @array: my pointer to array to search
 * @size: size of the array
 * @value: its the value to search in my array
 * Return: index where the value is created
 */
int binary_search(int *array, size_t size, int value)
{
	size_t lft = 0;
	size_t rgt = size - 1;
	size_t mid;

	if (array == NULL)
		return (-1);

	while (lft <= rgt)
	{
		mid = (lft + rgt) / 2;
		print_array(array, lft, rgt);

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			lft = mid + 1;
		else
			rgt = mid - 1;
	}
	return (-1);
}


