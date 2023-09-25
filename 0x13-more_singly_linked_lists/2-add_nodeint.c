#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginnong of a listint_t list
 * @head: memory of a pointer to a listint_t list
 * @n: data (number)
 *
 * Return: address of the new element or NULL
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));

	if (!new || !head)
		return (NULL);

	new->n = (int)n;
	new->next = *head;

	*head = new;

	return (new);
}
