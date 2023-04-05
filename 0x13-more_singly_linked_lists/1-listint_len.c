#include "lists.h"

/**
 * listint_len - returns the number of elements in listint_t list.
 * @h: Integer of listint_len
 *
 * Return: Number of elements in a linked list
 */

size_t listint_len(const listint_t *h)
{
size_t num_node = 0;

for (; h != NULL; h = h->next)
	num_node++;

return (num_node);
}
