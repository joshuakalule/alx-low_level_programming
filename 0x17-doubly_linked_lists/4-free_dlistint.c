#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t
 * @head: pointer to the list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current, *next_node;

	if (!head)
		return;
	current = head;

	while (1)
	{
		next_node = current->next;
		free(current);
		current = next_node;
		if (!current)
			break;
	}
}
