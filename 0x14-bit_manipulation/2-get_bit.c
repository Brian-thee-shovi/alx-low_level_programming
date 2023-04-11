#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: the unknown number to search
 * @index: index of the bit
 *
 * Return: value of the bit at the index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int ky;

	if (index > 9)
		return (-1);
	ky = (n >> index) & 1;

	return (ky);
}
