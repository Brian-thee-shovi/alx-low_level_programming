#include "hash_tables.h"
/**
 * hash_table_delete - this deletes the hash table
 * @ht: hashtablle
 * Return: nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int ki;
	hash_node_t *n_node;
	hash_node_t *tpy;

	if (ht == NULL)
		return;
	for (ki = 0; ki < ht->size; ki++)
	{
		n_node = ht->array[ki];
		while (n_node != NULL)
		{
			tpy = n_node;
			n_node = n_node->next;
			free(tpy->key);
			free(tpy->value);
			free(tpy);
		}
		ht->array[ki] = NULL;
	}
	free(ht->array);
	free(ht);
}
