#include "lists.h"

/**
 * dlistint_len - counts the number of elements in a linked dlistint_t list
 * @h: pointer to the list
 * Return: number of elements in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	dlistint_t *current;
	size_t count;

	if (!h)
		return (0);
	count = 0;
	current = (dlistint_t *)h;
	while (1)
	{
		count++;
		current = current->next;
		if (!current)
			break;
	}
	return (count);
}
