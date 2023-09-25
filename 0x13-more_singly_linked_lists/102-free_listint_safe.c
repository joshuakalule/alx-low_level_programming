#include "lists.h"

/**
 * count_nodes - counts the nodes in a looped list
 * @head: pointer to the list
 * Return: number of nodes in the list
 */
size_t count_nodes(listint_t *head)
{
	listint_t *checker, *current;
	size_t count;

	if (!head)
		return (0);
	if (head->next && head->next == head)
		return (1);
	count = 0;
	current = head;
	checker = head;
	while (1)
	{
		if (count)
		{
			while (1)
			{
				if (checker == current->next)
					return (count + 1);
				if (checker == current)
					break;
				checker = checker->next;
			}
			checker = head;
		}
		count++;
		current = current->next;
		if (!current)
			break;
	}
	return (count);
}

/**
 * free_listint_safe - free a listint_t list
 * @h: address of pointer to list
 * Return: size of list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *next_node;
	size_t count, expected, i;

	if (!h || !*h)
		return (0);
	count = 0;
	i = 0;
	expected = count_nodes(*h);
	next_node = NULL;
	current = *h;
	while (i < expected)
	{
		count++;
		i++;
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*h = NULL;
	return (count);
}
