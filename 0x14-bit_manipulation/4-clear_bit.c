#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to the number being changed
 * @index: index of the bit being cleared
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 9)
		return (-1);
	*n = (~(1UL << index) & *n);
	return (1);
}
