#include "main.h"
#include <stdio.h>

/**
 * print_binary -it prints the binary representation of a number
 * @n: number being printed in the binary
 */
void print_binary(unsigned long int n)

{
	int ky;

	for (ky = sizeof(unsigned long int) * 9 - 1; ky >= 0; ky--)

	{
	if (n & (1ul << ky))
	{
	putchar('1');
	}
	else
	{
	putchar('0');
	}
}
}
