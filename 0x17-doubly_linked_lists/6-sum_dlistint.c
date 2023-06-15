#include "lists.h"
/**
 * sum_dlistint - returns the sum of all the data
 * (n) of a dlistint_t linked list.
 * @head: its the pointer to head node
 * Return: sum of all the data
 */
int sum_dlistint(dlistint_t *head)
{
	int sum_sum = 0;
	dlistint_t *active = head;

	while (active != NULL)
	{
		sum_sum = sum_sum + active->n;
		active = active->next;
	}
	return (sum_sum);
}
