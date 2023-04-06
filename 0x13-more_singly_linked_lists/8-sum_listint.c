#include "lists.h"

/**
 * sum_listint - calculattes the sum
 * @head: 1st node in the linked list
 *
 * Return:resulting sum
 */
int sum_listint(listint_t *head)

{
	int zan = 0;

	listint_t *temp = head;

	while (temp)
	{
		zan += temp->n;
		temp = temp->next;
	}
	return (zan);
}
