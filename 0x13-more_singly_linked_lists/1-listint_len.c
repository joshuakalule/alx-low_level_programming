#include "lists.h"

/**
 * listint_len - counts the number of elements in a linked list
 * @h: pointer to the list
 *
 * Return: number of elements in the list
 */
size_t listint_len(const listint_t *h)
{
	listint_t *current = (listint_t *)h;
	size_t nodes = 0;

	if (!h)
		return (0);

	while (1)
	{
		nodes++;
		current = current->next;
		if (!current)
			break;
	}
	return (nodes);
}
