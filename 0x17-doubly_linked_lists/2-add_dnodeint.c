#include "lists.h"

/**
 * add_dnodeint - adds a new node at the start of a dlistint_t list
 * @head: address of a pointer to the list
 * @n: node data
 *
 * Return: address of new element , otherwise NULL
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (!head || !new)
		return (NULL);

	new->n = (int)n;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;
	new->next = *head;
	*head = new;
	return (new);
}
