#include "main.h"

/**
 * get_endianness - checks the endianness
 * Return: 0 if big endian or, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int ky = 1;
	char *c = (char *) &ky;

	return (*c);
}
