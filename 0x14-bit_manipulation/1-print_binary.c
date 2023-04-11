#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * print_binary -it prints the binary representation of a number
 * @n: number being printed in the binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int jax = 1ul << (sizeof(unsigned long int) * 8 - 1);

	while (jax > 0)
	{
		if (n & jax)
		{
			putchar('1');
		} else
		{
			putchar('0');
		}
		jax >>= 1;
	}
}
