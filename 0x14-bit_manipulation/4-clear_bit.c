#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index in this code
 * @n: this is a pointer
 * @index: index of the bit being set
 * Return: 1 on success and -1 on failure
 * author: Brian Gicovi
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int ja;

	if (index > 63)
		return (-1);
	ja = 1 << index;
	if (*n & ja)
		*n ^= ja;
	return (1);
}
