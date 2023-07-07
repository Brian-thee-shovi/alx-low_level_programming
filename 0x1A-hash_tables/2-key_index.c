#include "hash_tables.h"
/**
 * key_index - func returns index to place item in the hashTABLE
 * @key: item being placed
 * @size: array size in the hash table
 * Return: the index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int ki_value =  hash_djb2(key);
	unsigned long int index_xi = ki_value % size;

	return (index_xi);
}
