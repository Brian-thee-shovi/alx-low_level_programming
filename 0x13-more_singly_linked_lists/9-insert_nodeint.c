#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer of a pointer to the 1st node in the list
 * @idx: position where new node is being added
 * @n: value to insert the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int f;
	listint_t *lex;
	listint_t *temp = *head;

	lex = malloc(sizeof(listint_t));
	if (!lex || !head)
		return (NULL);
	lex->n = n;
	lex->next = NULL;

	if (idx == 0)
	{
		lex->next = *head;
		*head = lex;
		return (lex);
	}
	for (f = 0; temp && f < idx; f++)
	{
		if (f == idx - 1)
		{
			lex->next = temp->next;
			temp->next = lex;
			return (lex);
		}
		else
			temp = temp->next;
	}
	return (NULL);
}
