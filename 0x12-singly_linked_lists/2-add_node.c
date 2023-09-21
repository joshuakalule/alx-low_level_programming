#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to a pointer to head of type list_t
 * @str: data for the node
 *
 * Return: the address of the new element, otherwise NULL
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

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

	new->next = *head;
	*head = new;

	return (new);
}
