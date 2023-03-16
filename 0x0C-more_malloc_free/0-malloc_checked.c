#include "main.h"

/**
 * malloc_checked-allocates memory using malloc.
 *
 * @b: memory to be allocated.
 *
 * Return: a pointer to the allocated memery.
 */
void *malloc_checked(unsigned int b)
{
void *i;

i = malloc(b);
if (i == NULL)
exit(98);
return (i);

}
