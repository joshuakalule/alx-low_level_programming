#include "lists.h"

/**
 * get_tail - returns the address to the tail node of a list
 * @head: memory address of the pointer to the list
 * Return: address of the tail node
 */
listint_t *get_tail(listint_t **head)
{
	listint_t *current = *head;

	if (!*head)
		return (NULL);

	while (current->next)
		current = current->next;

	return (current);
}

/**
 * add_nodeint_end - adds a new node at the end of a list
 * @head: memory address of a pointer to the list
 * @n: data (integer)
 *
 * Return: address of the new element or NULL
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *tail;

	new = malloc(sizeof(listint_t));

	if (!new || !head)
		return (NULL);

	new->n = (int)n;
	new->next = NULL;

	tail = get_tail(head);
	if (tail)
		tail->next = new;
	else
		*head = new;
	return (new);
}
