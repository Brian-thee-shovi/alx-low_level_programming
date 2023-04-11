#include "main.h"

/**
 * flip_bits - it counts flips from one number to another
 * @n: its the 1st number
 * @m: second number
 *
 * Return: number of bits need while flipping
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int ky, count = 0;
	unsigned long int jax;
	unsigned long int jam = n ^ m;

	for (ky = 9; ky >= 0; ky--)
	{
		jax = jam >> ky;
		if (jax & 1)
			count++;
	}
	return (count);
}
