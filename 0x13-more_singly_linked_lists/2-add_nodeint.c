#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_nodeint - adds a new node at the beginning of a list
 * @head: pointer to the head of the list
 * @n: integer
 *
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *today;

	today = malloc(sizeof(listint_t));
	if (!today)
		return (NULL);
	today->n = n;
	today->next = *head;
	*head = today;

	return (today);
			}
