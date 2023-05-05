#include "main.h"

/**
 * get_endianness - this func checkz the endianness
 * Return: 0 if big endian, 1 if little endian in code below
 * author: Brian.G
 */
int get_endianness(void)
{
	unsigned int maxx;
	char *z;

	maxx = 1;
	z = (char *) &maxx;
	return ((int) *z);
}
