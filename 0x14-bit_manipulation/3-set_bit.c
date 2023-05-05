#include "main.h"

/**
 * set_bit - func sets the value of a bit to 1 at a given index in this code
 * @n: pointer
 * @index: index of the bit being set to 1
 * Return: 1 on success and -1 on failure
 * author:Brian Gicovi
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int baxx = 0x01;

	baxx <<= index;
	if (baxx == 0)
		return (-1);
	*n |= baxx;
	return (1);
}
