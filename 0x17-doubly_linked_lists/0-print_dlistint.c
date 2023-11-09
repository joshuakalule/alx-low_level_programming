#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: pointer to the list
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	dlistint_t *current;
	size_t count;

	if (!h)
		return (0);
	count = 0;
	current = (dlistint_t *)h;
	while (1)
	{
		printf("%d\n", current->n);
		count++;
		current = current->next;
		if (!current)
			break;
	}
	return (count);
}
