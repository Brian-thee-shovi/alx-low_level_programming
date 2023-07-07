#include "hash_tables.h"
/**
 * hash_table_print - func displays hashTABLE
 * @ht: this is hashtable being displayed
 * Return: nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int ki;
	hash_node_t *n_node;
	int p_hash = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (ki = 0; ki < ht->size; ki++)
	{
		n_node = ht->array[ki];
		while (n_node != NULL)
		{
			if (p_hash == 1)
				printf(", ");
			printf("'%s': '%s'", n_node->key, n_node->value);
			p_hash = 1;
			n_node = n_node->next;
		}
	}
	printf("}\n");
}

