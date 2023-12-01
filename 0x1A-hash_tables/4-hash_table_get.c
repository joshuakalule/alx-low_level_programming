#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: hast table array
 * @key: key
 *
 * Return: value associated with the element , NULL if key could not be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *node;

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
