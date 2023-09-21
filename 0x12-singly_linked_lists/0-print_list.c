#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the list
 *
 * Return: number of nodes in the list
 */
size_t print_list(const list_t *h)
{
	list_t *current_list = (list_t *)h;
	char *string;
	unsigned int length;
	size_t n = 0;

	if (!h)
		return (0);

	while (1)
	{
		n++;
		if (current_list->str == NULL)
		{
			string = "(nil)";
			length = 0;
		}
		else
		{
			string = current_list->str;
			length = current_list->len;
		}

		printf("[%u] %s\n", length, string);
		if (current_list->next == NULL)
			break;

		current_list = current_list->next;

	}

	return (n);
}
