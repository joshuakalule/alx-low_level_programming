#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index
 * @head: address of the pointer to the list
 * @index: position of interest
 *
 * Return: 1 (SUCCESS) otherwise -1 (FAIL)
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *parent, *current, *next_node;
	unsigned int i;

	if (!head || !*head)
		return (-1);

	i = 0;
	parent = NULL;
	current = *head;
	while (1)
	{
		if (i == index)
			break;
		i++;
		parent = current;
		current = current->next;
		if (!current)
			return (-1);
	}
	next_node = current->next;
	free(current);

	if (!parent)
		*head = next_node;
	else
		parent->next = next_node;

	if (next_node)
		next_node->prev = parent;

	return (1);
}
