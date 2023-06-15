#include "lists.h"
/**
 * free_dlistint - this frees a Dlinked list
 * @head: this pointer to the headnode
 * Return: nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *free_h;

	while (head)
	{
		free_h = head->next;
		free(head);
		head = free_h;
	}
}
