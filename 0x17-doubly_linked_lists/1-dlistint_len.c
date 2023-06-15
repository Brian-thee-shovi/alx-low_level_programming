#include "lists.h"
/**
 * dlistint_len - prints number of elements
 * @h: its the pointer to the head node
 * Return: number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t index_x = 0;

	while (h != 0)
	{
		index_x++;
		h = h->next;
	}
	return (index_x);
}
