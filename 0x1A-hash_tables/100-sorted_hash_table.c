#include "hash_tables.h"

/**
 * shash_table_create - create a sorted hash table
 * @size: size of the hash table
 * Return: pointer to ths hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;
	unsigned long int i;

	if (size == 0)
		return (NULL);
	table = malloc(sizeof(shash_table_t));
	if (!table)
		return (NULL);
	table->size = size;
	table->shead = NULL;
	table->stail = NULL;

	table->array = malloc(sizeof(shash_node_t *) * size);
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		table->array[i] = (shash_node_t *)NULL;
	return (table);
}

/**
 * add_to_list - add node to sorted linked list
 * @ht: pointer to the has table
 * @new: node to add
 *
 * Return: 1 (SUCCESS) | 0 (FAIL)
 */
int add_to_list(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *node, *prev;

	if (!ht || !new)
		return (0);
	prev = NULL;
	node = ht->shead;
	while (node)
	{
		ht->stail = node;
		if (strcmp(node->key, new->key) >= 0)
			break;
		prev = node;
		node = node->snext;
	}
	new->sprev = prev;
	if (prev)
		prev->snext = new;
	else
		ht->shead = new;
	new->snext = node;
	if (node)
		node->sprev = new;
	/* assign tail */
	node = ht->stail;
	while (node)
	{
		ht->stail = node;
		node = node->snext;
	}
	return (1);
}

/**
 * add_node - add node at the beginning of the list
 * @ht: pointer to the hash table
 * @idx: index of the hash table array to add to
 * @new: node to add
 *
 * Return: 1 (Success) , 0 (Failure)
 */
int add_node(shash_table_t *ht, const unsigned long int idx,
		shash_node_t *new)
{
	shash_node_t *prev;

	if (!ht || !new)
		return (0);
	/* add to array */
	prev = ht->array[idx];
	ht->array[idx] = new;
	new->next = prev;

	/* add to sorted linked list */
	if (ht->shead == NULL) /* first element in hash table */
	{
		ht->shead = new;
		ht->stail = new;
		new->sprev = NULL;
		new->snext = NULL;
	}
	else /* insert appropriately */
	{
		if (add_to_list(ht, new) == 0)
			return (0); /* failed to insert */
	}
	return (1);
}

/**
 * create_node - helper function to create new node
 * @key: key
 * @value: value
 *
 * Return: pointer to the new node
 */
shash_node_t *create_node(const char *key, const char *value)
{
	shash_node_t *new;

	if (!key || *key == '\0')
		return (NULL);
	new = malloc(sizeof(shash_node_t));

	new->key = strdup(key);

	if (value)
		new->value = strdup(value);
	else
		new->value = NULL;

	new->next = NULL;
	new->snext = NULL;
	new->sprev = NULL;
	return (new);
}

/**
 * shash_table_set - adds an element to the sorted hash table
 * @ht: pointer to the hash table
 * @key: key
 * @value: value
 *
 * Return: 1 (SUCCESS) | 0 (otherwise)
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	shash_node_t *new;

	if (!ht || !key || *key == '\0')
		return (0);
	idx = key_index((unsigned char *)key, ht->size);
	if (ht->array[idx] == NULL)
	{
		/* add directly */
		new = create_node(key, value);
		if (!new)
			return (0);
		if (add_node(ht, idx, new) == 0)
			/* free new */
			return (0);
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
			/* colision, add new key to start of existing list */
			new = create_node(key, value);
			if (!new)
				return (0);
			if (add_node(ht, idx, new) == 0)
				/* free new */
				return (0);
		}
	}
	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: hash table array
 * @key: key
 *
 * Return: value associated with the key , otherwise NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *node;

	if (!ht || !key)
		return (NULL);
	idx = key_index((unsigned char *)key, ht->size);
	if (ht->array[idx] == NULL)
		return (NULL);

	node = ht->array[idx];
	while (node)
	{
		if (strcmp(node->key, key) == 0)
			/* positive match */
			return (node->value);
		node = node->next;
	}
	/* not found */
	return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	int start;

	if (!ht)
		return;

	printf("{");
	start = 1;
	node = ht->shead;
	while (node)
	{
		if (start != 1)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		start = 0;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	int start;

	if (!ht)
		return;

	printf("{");
	start = 1;
	node = ht->stail;
	while (node)
	{
		if (start != 1)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		start = 0;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a hash table
 * @ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *next_node;
	unsigned long int i;

	if (!ht)
		return;
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			next_node = node->next;
			free(node->key);
			if (node->value)
				free(node->value);
			free(node);
			node = next_node;
		}
	}
	free(ht->array);
	free(ht);
}
