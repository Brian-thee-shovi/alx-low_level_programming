#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index ,at certain position
 * @head:address of a pointer of the 1st element ib the list
 * @index: index of the node being delete
 *
 * Return: 1,when successful or -1,if it fails
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	listint_t *meme = NULL;
	unsigned int z = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	while (z < index - 1)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		z++;
	}
	meme = temp->next;
	temp->next = meme->next;
	free(meme);

	return (1);
}
