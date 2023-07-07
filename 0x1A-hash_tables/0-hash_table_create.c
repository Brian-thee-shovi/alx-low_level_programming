#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - this func creates a hash Table
 * @size: array size
 * Return: new hast table created
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *newtable_t;
	unsigned long int ki;

	newtable_t = (hash_table_t *)malloc(sizeof(hash_table_t));
	if (newtable_t == NULL)
		return (NULL);

	newtable_t->array = (hash_node_t **)malloc(sizeof(hash_node_t *) * size);
	if (newtable_t->array  == NULL)
	{
		free(newtable_t);
		return (NULL);
	}
	for (ki = 0; ki < size; ki++)
	{
		newtable_t->array[ki] = NULL;
	}
	newtable_t->size = size;
	return (newtable_t);
}

