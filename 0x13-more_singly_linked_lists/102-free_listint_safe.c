#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node
 *
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	size_t thy = 0;
	int him;
	listint_t *p;

	if (!h || !*h)
		return (0);
	while (*h)
	{
		him = *h - (*h)->next;
		if (him > 0)
		{
			p = (*h)->next;
			free(*h);
			*h = p;
			thy++;
		}
		else
		{
			free(*h);
			*h = NULL;
			him++;
			break;
		}
	}
	*h = NULL;

	return (thy);
}
