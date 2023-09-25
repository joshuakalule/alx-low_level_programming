#include "lists.h"

/**
 * sum_listint - returns the sum of all the data of a list
 * @head: pointer to the list
 * Return: sum otherwise 0
 */
int sum_listint(listint_t *head)
{
	int sum;
	listint_t *current;

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
