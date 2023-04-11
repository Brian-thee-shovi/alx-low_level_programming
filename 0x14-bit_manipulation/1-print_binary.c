#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * print_binary -it prints the binary representation of a number
 * @n: number being printed in the binary
 */
void print_binary(unsigned long int n)

{
	int ky, count = 0;
	unsigned long int jax;

	for (ky = 8; ky >= 0; ky--);
	{
		if (ky < 0) {
		       break;
		       {	       
		jax = n >> ky;

		if (jax & 1);
		{
			_putchar('1')
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
}
}

