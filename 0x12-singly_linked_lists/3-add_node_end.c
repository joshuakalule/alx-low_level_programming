#include "lists.h"

/**
 * get_tail - gets the tail node of the list pointed to by head
 * @head: pointer to pointer to head
 *
 * Return: pointer to tail or NULL if no tail
 */
list_t *get_tail(list_t **head)
{
	list_t *tmp;

	if (!*head)
		return (NULL);

	tmp = *head;

	while (tmp->next)
		tmp = tmp->next;

	return (tmp);
}

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to a pointer to head of type list_t
 * @str: data for the node
 *
 * Return: the address of the new element, otherwise NULL
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *tail;

	new = malloc(sizeof(list_t));
	if (!new || !head)
		return (NULL);

	if (!str)
	{
		new->str = NULL;
		new->len = 0;
	}
	else
	{
		new->str = strdup(str);
		new->len = strlen(str);
	}
	new->next = NULL;

	tail = get_tail(head);

	if (tail)
		tail->next = new;
	else
		*head = new;

	return (new);
}
