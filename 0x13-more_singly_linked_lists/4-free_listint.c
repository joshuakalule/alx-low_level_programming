#include "lists.h"

/**
 * free_listint - free a listint_t list
 * @head: pointer to the list
 */
void free_listint(listint_t *head)
{
	listint_t *current = head, *next;

	if (head == NULL)
		return;
	while (1)
	{
		next = current->next;
		free(current);
		current = next;
		if (current == NULL)
			break;
	}
}
