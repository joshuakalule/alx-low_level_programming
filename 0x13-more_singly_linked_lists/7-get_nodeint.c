#include "lists.h"

/**
 * get_nodeint_at_index - gets the nth node of a listint_t list
 * @head: pointer to the list
 * @index: position of interest
 *
 * Return: node at index otherwise NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count;
	listint_t *current;

	if (!head)
		return (NULL);

	count = 0;
	current = head;
	while (1)
	{
		if (count == index)
			break;
		count++;
		current = current->next;
		if (!current)
			return (NULL);
	}
	return (current);
}
