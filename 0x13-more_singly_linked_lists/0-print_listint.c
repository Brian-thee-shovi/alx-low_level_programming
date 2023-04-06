#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints all elements of a linked list
 * @h:linked list of type listint_t
 * Return:number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t lol = 0;

	while (h)
	{
		printf("%d\n", h->n);
				lol++;
				h = h->next;;
				}

				return (lol);
				}
