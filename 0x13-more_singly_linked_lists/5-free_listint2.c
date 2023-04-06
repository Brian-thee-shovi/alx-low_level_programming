#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @head: address to the listint_t being freed
 */
void free_listint2(listint_t **head)
{
	listint_t *many;

	if (head == NULL)
		return;
	while (*head)
	{
		many = (*head)->next;
		free(*head);
		*head = many;
	}
	*head = NULL;
}
