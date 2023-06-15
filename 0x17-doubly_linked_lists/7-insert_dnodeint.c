#include "lists.h"
/**
 * insert_dnodeint_at_index - this inserts a new node at a given position
 * @h: Dpointer to the head node
 * @idx: index of list where node is being added
 * @n: data being put in the new node
 * Return: NULL IF it fails or address of the new node on success
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *alpha_node;
	dlistint_t *active_h = *h;

	unsigned int ram = 0;

	if (idx == 0)
		return (add_dnodeint(h, n));
	while (active_h && ram < idx - 1)
	{
		active_h = active_h->next;
		ram++;
	}
	if (!active_h)
		return (NULL);
	if (!active_h->next)
		return (add_dnodeint_end(h, n));
	alpha_node = malloc(sizeof(dlistint_t));
	if (alpha_node == NULL)
		return (NULL);
	alpha_node->n = n;
	alpha_node->next = active_h->next;
	alpha_node->prev = active_h;
	active_h->next->prev = alpha_node;
	active_h->next = alpha_node;

	return (alpha_node);
}
