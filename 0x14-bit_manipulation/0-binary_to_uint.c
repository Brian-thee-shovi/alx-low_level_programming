#include "main.h"

/**
 * binary_to_uint - it converts a binary number to unsigned int
 * @b: this is the string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int ky;
	unsigned int jax = 0;

if (!b)
return (0);

for (ky = 0; b[ky]; ky++)
{
if (b[ky] < '0' || b[ky] > '1')

return (0);
jax = 2 * jax + (b[ky] - '0');
}
return (jax);
}
