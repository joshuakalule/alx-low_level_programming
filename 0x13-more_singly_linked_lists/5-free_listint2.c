#include "lists.h"

/**
 * free_listint2 - free a listint_t list
 * @head: memory of a pointer to the list
 */
void free_listint2(listint_t **head)
{
	listint_t *current, *next;

	if (!head || !*head)
		return;
	current = *head;
	while (1)
	{
		next = current->next;
		free(current);
		current = next;
		if (current == NULL)
			break;
	}
	*head = NULL;
}
