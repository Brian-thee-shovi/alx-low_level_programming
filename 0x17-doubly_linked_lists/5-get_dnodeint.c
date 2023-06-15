#include "lists.h"
/**
 * get_dnodeint_at_index - this returns the nth node in a Dlinked list
 * @head: its a pointer to the head node
 * @index: position of the node being returned
 * Return: the nth node innit
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *active = head;
	unsigned int alpha = 0;

	while (active != NULL)
	{
		if (alpha == index)
			return (active);

		active = active->next;
		alpha++;
	}
	return (NULL);
}
