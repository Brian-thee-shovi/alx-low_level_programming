#include "main.h"


/**
* binary_to_uint - Thisconverts a binary number to an unsigned int in this code
* @b: this is a pointer to a string of the binary number(0&1)
* Return: the converted number
* Author: Brian Gicovi
*/
unsigned int binary_to_uint(const char *b)
{
int f;
unsigned int Maxx = 0;
if (!b)
return (0);
for (f = 0; b[f]; f++)
{
if (b[f] < '0' || b[f] > '1')
return (0);
Maxx = 2 * Maxx + (b[f] - '0');
}
return (Maxx);
}
