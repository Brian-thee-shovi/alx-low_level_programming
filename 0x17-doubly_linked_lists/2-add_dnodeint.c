#include "lists.h"
/**
 * add_dnodeint - this adds node at the start of linked list
 * @head: pointer to the 1st node
 * @n: data of the node
 * Return: null if failed or address of the new element
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node_x;

	node_x = malloc(sizeof(dlistint_t));
	if (node_x == NULL)
		return (NULL);
	node_x->n = n;
	node_x->prev = NULL;
	node_x->next = *head;

	if (*head != NULL)
		(*head)->prev = node_x;
	*head = node_x;
	return (node_x);
}
