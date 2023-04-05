#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end -  adds a new node at the end of a listint_t list.
 * @head: pointer to the 1st element in the list
 * @n: integer to be added
 * Return: pointer to the new node or null if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new;
listint_t *temp = *head;

new = malloc(sizeof(listint_t));
if (!new)
	return (NULL);
new->n = n;
new->next = NULL;
if (*head == NULL)
{
	*head = new;
	return (new);
}
  while (temp->next)
{
	temp = temp->next;
}
	temp->next = new;
	return (new);
	}
