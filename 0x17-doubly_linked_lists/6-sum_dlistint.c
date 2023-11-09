#include "lists.h"

/**
 * sum_dlistint - sums up all the data of a dlistint_t list
 * @head: pointer to a list
 * Return: sum otherwise 0
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current;
	int sum;

	if (!head)
		return (0);

	sum = 0;
	current = head;
	while (1)
	{
		sum += current->n;
		current = current->next;
		if (!current)
			break;
	}
	return (sum);
}
