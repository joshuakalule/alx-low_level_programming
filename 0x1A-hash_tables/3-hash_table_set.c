#include "hash_tables.h"

/**
 * add_node - add node at the beginning of the list
 * @head: head of the list
 * @new: node to insert
 *
 * Return: poiner to the new node added
 */
hash_node_t *add_node(hash_node_t **head, hash_node_t *new)
{
	hash_node_t *prev;

	if (!head || !new)
		return (NULL);
	prev = *head;
	*head = new;
	new->next = prev;
	return (*head);
}

/**
 * create_node - helper fucntion to create a new node
 * @key: key
 * @value: value
 *
 * Return: pointer to the new node
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new;

	if (!key || *key == '\0')
		return (NULL);
	new = malloc(sizeof(hash_node_t));
	if (!new)
		return (NULL);
	new->key = strdup(key);
	if (value)
		new->value = strdup(value);
	else
		new->value = NULL;
	new->next = NULL;
	return (new);
}


/**
 * hash_table_set - adds an element to the hash_table
 * @ht: pointer to the hash table
 * @key: key
 * @value: value associated with the key
 *
 * Return: 1 (SUCCESS) | 0 (otherwise)
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *new;

	if (!ht || !key || *key == '\0')
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	if (ht->array[idx] == NULL)
	{
		/* add directly */
		new = create_node(key, value);
		if (!new)
			return (0);
		ht->array[idx] = new;
	}
	else
	{
		/* index already occupied */
		if (strcmp(ht->array[idx]->key, key) == 0)
		{
			/* key already exists */
			if (ht->array[idx]->value)
				free(ht->array[idx]->value);
			ht->array[idx]->value = strdup(value);
		}
		else
		{
			/* collision */
			/* add new key to the beginning of the existing list */
			new = create_node(key, value);
			if (!new)
				return (0);
			ht->array[idx] = add_node(&(ht->array[idx]), new);
		}
	}
	return (1);
}
