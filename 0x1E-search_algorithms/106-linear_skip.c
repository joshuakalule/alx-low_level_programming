#include "search_algos.h"

/**
 * linear_skip - execution of skip list searching
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *low, *high;

	if (list == NULL)
		return (NULL);

	node = low = list;
	while (node)
	{
		low = node;
		node = node->express;
		if (node)
			printf("Value checked at index [%ld] = [%d]\n", node->index,
					node->n);
		if (node == NULL || node->n >= value)
		{
			if (node == NULL)
			{
				high = low;
				while (high->next)
					high = high->next;
			}
			else
			{
				high = node;
			}
			printf("Value found between indexes [%ld] and [%ld]\n", low->index,
					high->index);
			node = low;
			while (node != NULL && node != high->next)
			{
				printf("Value checked at index [%ld] = [%d]\n", node->index,
					node->n);
				if (node->n == value)
					return (node);
				node = node->next;
			}
			return (NULL);
		}
	}
	return (NULL);
}
