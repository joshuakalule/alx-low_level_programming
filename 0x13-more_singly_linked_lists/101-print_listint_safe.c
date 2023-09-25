#include "lists.h"

/**
 * _free_my_list - frees a listlist_t list
 * @head: pointer to list
 */
void _free_my_list(listlist_t *head)
{
	listlist_t *current, *next_node;

	if (!head)
		return;
	current = head;
	while (1)
	{
		next_node = current->next;
		free(current);
		current = next_node;
		if (!current)
			break;
	}
	head = NULL;
}


/**
 * add_list_node - add node to helper list
 * @head: address to pointer to the helper list
 * @node_ptr: pointer to a listint_t list node
 *
 * Return: pointer to added node
 */
listlist_t *add_list_node(listlist_t **head, listint_t *node_ptr)
{
	listlist_t *new, *child;

	new = malloc(sizeof(listlist_t));
	if (!head || !new)
		return (NULL);
	new->node = node_ptr;
	if (*head)
		child = *head;
	else
		child = NULL;
	*head = new;
	new->next = child;

	return (new);
}

/**
 * check_for - searches a listlist list for node_ptr
 * @node_ptr: pointer being looked for
 * @head: address to pointer to a listlist_t list
 *
 * Return: 1 (found) , 0 (not found)
 */
int check_for(listint_t *node_ptr, listlist_t **head)
{
	listlist_t *current;

	if (!head || !*head)
		return (0);

	current = *head;
	while (1)
	{
		if (node_ptr == current->node)
			return (1);
		current = current->next;
		if (!current)
			break;
	}
	return (0);
}

/**
 * print_listint_safe - prints a listint_t list
 * @head: pointer to the list
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	listint_t *current;
	listlist_t *checklist;
	size_t count;

	if (!head)
		return (0);

	count = 0;
	checklist = NULL;
	current = (listint_t *)head;
	while (1)
	{
		if (!check_for(current, &checklist))
		{
			add_list_node(&checklist, current);
		}
		else
		{
			printf("-> [%p] %d\n", (void *)current, current->n);
			break;
		}

		printf("[%p] %d\n", (void *)current, current->n);
		count++;
		current = current->next;
		if (!current)
			break;
	}
	_free_my_list(checklist);
	return (count);
}
