#include "lists.h"

/**
 * reverse_listint - reverses a listint_t list
 * @head: address of the pointer to the list
 * Return: pointer to first node of reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *current, *next_node;

	if (!head || !*head)
		return (NULL);

	current = (*head)->next;
	(*head)->next = NULL;
	while (1)
	{
		if (current == NULL)
			break;

		next_node = current->next;
		current->next = *head;
		*head = current;
		current = next_node;
	}
	return (*head);
}
