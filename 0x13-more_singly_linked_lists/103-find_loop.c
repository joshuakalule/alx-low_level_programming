#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: pointer to list
 * Return: address of the node where loop starts or NULL
 *
 * Description: using Floyd's algorithm
 *
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *hare, *snail;

	if (!head)
		return (NULL);
	snail = head;
	hare = head;
	while (1)
	{
		if (hare && hare->next)
			hare = hare->next->next;
		else
			hare = NULL;

		snail = snail->next;
		if (!snail)
			break;

		if (hare == snail)
			hare = NULL;
		if (hare == NULL)
		{
			if (head == snail)
				return (snail);
			head = head->next;
		}
	}
	return (NULL);
}
