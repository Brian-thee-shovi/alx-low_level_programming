#include <math.h>
#include "search_algos.h"

/**
 * jump_search - searches value in sorted array contain ints
 * @array: array to look into
 * @size: size of the array
 * @value: value to search
 * Return: index of the value found, or -1 when not found
 */

int jump_search(int *array, size_t size, int value)
{
	size_t start, final, nyayo;

	if (!array || size == 0)
		return (-1);
	nyayo = sqrt(size);
	start = 0, final = nyayo;

	while (start < size)
	{
		printf("Value checked array[%lu] = [%d]\n", start, array[start]);
		if (final < size)
		{
			if (array[start] <= value && value <= array[final])
			{
				printf("Value found between indexes [%lu] and [%lu]\n", start, final);
				break;
			}
		}
		else
		{
			if (array[start] <= value)
			{
				printf("Value found between indexes [%lu] and [%lu]\n", start, final);
				break;
			}
		}
		start = final;
		final = start + nyayo;
	}
	while (start <= final)
	{
		if (start == size)
			return (-1);
		printf("Value checked array[%lu] = [%d]\n", start, array[start]);
		if (array[start] == value)
			return (start);
		start++;
	}
	return (-1);
}
