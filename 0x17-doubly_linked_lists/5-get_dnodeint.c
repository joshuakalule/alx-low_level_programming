#include "lists.h"

/**
 * get_dnodeint_at_index - gets the nth node at a dlistint_t list
 * @head: pointer to the list
 * @index: position of interest
 *
 * Return: return the nth node, otherwise NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	if (!head)
		return (NULL);

	i = 0;
	current = head;
	while (1)
	{
		if (index == i)
			break;
		i++;
		current = current->next;
		if (!current)
			return (NULL);
	}
	return (current);
}
