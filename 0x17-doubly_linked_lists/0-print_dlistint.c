#include "lists.h"
/**
 * print_dlistint - prints element of a LINKED list
 * @h: pointer to head node in this code
 * Return: number of nodes
 * author: Brian.G
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t index_x = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		index_x++;
	}
	return (index_x);
}
