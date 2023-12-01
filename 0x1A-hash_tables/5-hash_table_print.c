#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	int start;

	if (!ht)
		return;

	printf("{");
	start = 1;
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		if (node == NULL)
			continue;
		if (start != 1)
			printf(", ");
		while (node)
		{
			printf("'%s': '%s'", node->key, node->value);
			if (node->next)
				printf(", ");
			node = node->next;
		}
		start = 0;
	}
	printf("}\n");
}
