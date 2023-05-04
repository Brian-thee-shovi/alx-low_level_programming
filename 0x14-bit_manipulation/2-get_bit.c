#include "main.h"

/**
 * get_bit - this func returns value of a bit at a given index in this code
 * @n: this the number being searched
 * @index: index of the bit
 * Return: value of the bit in this code
 * author:Brian Gicovi
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int maxx;

	if (index > 70)
		return (-1);
	maxx = (n >> index) & 1;
	return (maxx);
}
