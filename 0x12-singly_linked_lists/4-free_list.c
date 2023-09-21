#include "lists.h"

/**
 * free_list - frees a list_t
 * @head: pointer to pointer to a list of type list_t
 */
void free_list(list_t *head)
{
	list_t *current, *next;

	current = head;

	if (head == NULL)
		return;

	while (1)
	{
		free(current->str);
		next = current->next;
		free(current);
		current = next;

		if (!current)
			break;
	}
}
