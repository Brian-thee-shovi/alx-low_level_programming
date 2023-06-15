#include "lists.h"
/**
 * add_dnodeint_end - adds a new node at the end
 * @head: Dpointer to the head nodes
 * @n: data to my node
 * Return: address to the new element created
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *alpha_node = NULL;
	dlistint_t *node_x = NULL;

	alpha_node = malloc(sizeof(dlistint_t));
	if (alpha_node == NULL)
		return (NULL);
	alpha_node->n = n;

	if (*head)
	{
		node_x = *head;
		while (node_x->next != NULL)
			node_x = node_x->next;
		alpha_node->next = NULL;
		alpha_node->prev = node_x;
		node_x->next = alpha_node;
		return (alpha_node);
	}
	alpha_node->next = *head;
	alpha_node->prev = NULL;
	*head = alpha_node;
	return (*head);
}
