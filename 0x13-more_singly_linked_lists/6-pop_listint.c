#include "lists.h"

/** 
 * pop_listint - deletes the heah node of a linked list
 * @head: pointer to the 1st element in the linked list
 *
 * Return: the deleted element
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;

	int num;

	if (!head || !*head)
		return (0);

	num = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (num);
}
