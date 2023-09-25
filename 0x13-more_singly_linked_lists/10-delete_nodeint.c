#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node at index 'index'
 * @head: address to the pointer to the list
 * @index: position of interest
 *
 * Return: 1 (success) otherwise -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *parent, *current;
	unsigned int count;

	if (!head || !*head)
		return (-1);

	count = 0;
	current = *head;
	while (1)
	{
		if (count == index)
		{
			if (index == 0)
				*head = current->next;
			else
				parent->next = current->next;
			free(current);
			return (1);
		}
		count++;
		parent = current;
		current = current->next;
		if (!current && count != index)
			break;
	}
	return (-1);
}
