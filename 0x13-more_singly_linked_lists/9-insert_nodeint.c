#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: address of pointer to list
 * @idx: position of interest
 * @n: data for new node
 *
 * Return: address of new node otherwise NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *current, *parent;
	unsigned int count;

	new = malloc(sizeof(listint_t));
	if (!head || !new)
		return (NULL);

	new->n = n;
	count = 0;
	current = *head;
	parent = *head;
	while (1)
	{
		if (count == idx)
		{
			if (parent && count != 0)
				parent->next = new;
			else
				*head = new;
			new->next = current;
			break;
		}
		count++;
		parent = current;
		current = current->next;
		if (!current && count != idx)
			return (NULL);

	}
	return (new);
}
