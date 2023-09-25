#include "lists.h"

/**
 * print_listint - prints all elements of a listint_t list
 * @h: pointer to the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint(const listint_t *h)
{
	listint_t *current = (listint_t *)h;
	size_t nodes = 0;

	if (h == NULL)
		return (0);

	while (1)
	{
		printf("%i\n", current->n);
		nodes++;
		if (!current->next)
			break;
		current = current->next;
	}
	return (nodes);
}
