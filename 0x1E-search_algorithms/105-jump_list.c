#include "search_algos.h"
#include <math.h>

/**
 * min - get minimum
 * @a: number 1
 * @b: number 2
 *
 * Return: min
 */
size_t min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

/**
 * print_check - prints the value being checked
 * @node: current node
 * @prev: previous node
 */
void print_check(listint_t *node, listint_t *prev)
{
	if (node == NULL)
		printf("Value checked at index [%ld] = [%d]\n", prev->index, prev->n);
	else
		printf("Value checked at index [%ld] = [%d]\n", node->index,
				node->n);
}

/**
 * jump_list - searches for a value in a sorted list of integers jump search
 * @list: a pointer to the head of the list to search in
 * @size: number of nodes in list
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t m;
	listint_t *low, *current, *high, *prev;

	if (list == NULL)
		return (NULL);
	m = sqrt(size);
	low = current = list;
	while (1)
	{
		if (m == 0)
		{
			m = sqrt(size);
			print_check(current, prev);
			if (current == NULL || current->n >= value)
			{
				if (current == NULL)
					current = prev;
				printf("Value found between indexes [%ld] and [%ld]\n",
						low->index, current->index);
				high = current;
				current = low;
				while (current != NULL && current != high->next)
				{
					print_check(current, prev);
					if (current->n == value)
						return (current);
					current = current->next;
				}
				return (NULL);
			}
			low = current;
		}
		else
		{
			m--;
			prev = current;
			current = current->next;
		}
	}
	return (NULL);
}
