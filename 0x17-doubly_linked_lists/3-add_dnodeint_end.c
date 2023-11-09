#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: address of the pointer to the list
 * @n: data to be added
 *
 * Return: address of the new element otherwise NULL
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *current;

	new = malloc(sizeof(dlistint_t));
	if (!head || !new)
		return (NULL);
	new->n = (int)n;
	new->next = NULL;

	current = *head;
	if (!current)
	{
		*head = new;
	}
	else
	{
		while (current->next)
		{
			current = current->next;
		}
		current->next = new;
	}

	new->prev = current;
	return (new);
}
