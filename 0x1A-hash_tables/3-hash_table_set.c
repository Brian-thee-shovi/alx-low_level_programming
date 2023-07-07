#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - func adds element to my hash table
 * @ht: hashtable
 * @key: item placed in the hASH table
 * @value: value associated with the keys
 * Return: 1 if success ad zero on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int ki = 0;
	hash_node_t *other_node = NULL;
	hash_node_t *tpy = NULL;

	if (ht == NULL || key == NULL || (strcmp(key, "") == 0))
	{
		return (0);
	}

	ki = key_index((unsigned char *)key, ht->size);
	tpy = ht->array[ki];

	if (tpy && strcmp(key, tpy->key) == 0)
	{
		free(tpy->value);
		tpy->value = strdup(value);
		return (1);
	}

	other_node = malloc(sizeof(hash_node_t));

	if (other_node == NULL)
		return (0);

	other_node->key = strdup(key);
	other_node->value = strdup(value);

	other_node->next = ht->array[ki];

	ht->array[ki] = other_node;

	return (1);
}

