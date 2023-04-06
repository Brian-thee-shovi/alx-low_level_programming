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
listint_t *nasa;
listint_t *t = *head;

nasa = malloc(sizeof(listint_t));
if (!nasa)
	return (NULL);
nasa->n = n;
nasa->next = NULL;
if (*head == NULL)
{
	*head = nasa;
	return (nasa);
}
  while (t->next)
{
	t = t->next;
}
	t->next = nasa;
	return (nasa);
	}
