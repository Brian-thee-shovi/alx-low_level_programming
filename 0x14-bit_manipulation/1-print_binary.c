#include "main.h"

/**
 * print_binary - this prints binary rep of a number in this code
 * @n: number being printed in binary
 * Return: no return
 * author: Brian Gicovi
 */
void print_binary(unsigned long int n)
{
	int ja, maxx = 0;
	unsigned long int faxx;

	for (ja = 63; ja >= 0; ja--)
	{
		faxx = n >> ja;
		if (faxx & 1)
		{
			_putchar('1');
			maxx++;
		}
		else if (maxx)
			_putchar('0');
	}
	if (!maxx)
		_putchar('0');
}

