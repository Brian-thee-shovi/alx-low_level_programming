#include "lists.h"
/**
 * delete_dnodeint_at_index - deletes a node at index o a linked llist
 * @head: Dpointer to the headnode
 * @index: position of node being delleted
 * Return: 1 if success and -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int ram = 0; /*counter*/
	dlistint_t *active = *head;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(active);
		return (1);
	}
	while (active && ram < index)
	{
		active = active->next;
		ram++;
	}
	if (active == NULL)
		return (-1);
	active->prev->next = active->next;
	if (active->next != NULL)
		active->next->prev = active->prev;
	free(active);

	return (1);
}
