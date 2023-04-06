#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer oof the 1st node in the list
 *
 * Return: pointer to the first node in the new the
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *jue = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = jue;
		jue = *head;
		*head = next;

	}
	*head = jue;
	return (*head);
}
