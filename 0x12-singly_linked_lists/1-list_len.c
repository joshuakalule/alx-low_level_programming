#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list
 * @h: pointer to the list
 *
 * Return: number of nodes in the list
 */
size_t list_len(const list_t *h)
{
	list_t *current_list = (list_t *)h;
	size_t n = 0;

	if (!current_list)
		return (0);

	while (1)
	{
		n++;
		if (current_list->next == NULL)
			break;

		current_list = current_list->next;
	}

	return (n);
}
