#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: address of the pointer to the list
 * @idx: position of interest
 * @n: data
 *
 * Return: address of new node otherwise NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *current, *parent, *next_node;
	unsigned int i;

	new = malloc(sizeof(dlistint_t));
	if (!h || !new)
		return (NULL);
	new->n = n;

	i = 0;
	current = *h;
	parent = NULL;
	while (1)
	{
		if (idx == i)
			break;
		if (!current)
		{
			if (idx > 0)
				return (NULL);
			break;
		}
		i++;
		parent = current;
		current = current->next;
		if (!current && idx != i)
			return (NULL);
	}
	next_node = current;
	if (parent)
		parent->next = new;
	else
		*h = new;
	new->prev = parent;
	new->next = next_node;
	if (next_node)
		next_node->prev = new;

	return (new);
}
