#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to
 * flip to get from one number to another.
 *@n: 1st number in the code below
 *@m: 2nd number in the code below
*Return: number of bits to change
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int maxx, faxx = 0;
	unsigned long int ja;
	unsigned long int daxx = n ^ m;

	for (maxx = 63; maxx >= 0; maxx--)
	{
		ja = daxx >> maxx;
		if (ja & 1)
			faxx++;
	}
	return (faxx);
}
