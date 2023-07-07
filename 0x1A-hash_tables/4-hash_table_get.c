#include "hash_tables.h"
#include <string.h>
/**
 * hash_table_get - func retrieves value from the hashTable
 * @ht: the hash table
 * @key: key being associated with the value
 * Return: key if found, null if not
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *n_node;
	unsigned long int ki;

	if (ht == NULL || key == NULL)
		return (NULL);
	ki = key_index((const unsigned char *)key, ht->size);
	n_node = ht->array[ki];

	while (n_node != NULL)
	{
		if (strcmp(n_node->key, key) == 0)
			return (n_node->value);
		n_node = n_node->next;
	}
	return (NULL);
}
