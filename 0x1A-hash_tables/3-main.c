#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 *  * main - check the code
 *   *
 *    * Return: Always EXIT_SUCCESS.
 *     */
int main(void)
{
	hash_table_t *ht;
	unsigned long int i;
	hash_node_t *node;

	ht = hash_table_create(1024);
	hash_table_set(ht, "betty", "cool");
	hash_table_set(ht, "hetairas", "colision 1");
	hash_table_set(ht, "mentioner", "colision 1");

	hash_table_set(ht, "ball", "let us see");
	hash_table_set(ht, "joyful", "collision 2");
	hash_table_set(ht, "synaphea", "collision 2");

	hash_table_set(ht, "empty_string", "");
	hash_table_set(ht, "NULL_string", NULL);
	hash_table_set(ht, "s1", "testing");
	hash_table_set(ht, "s2", "testing 2");

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i])
		{
			printf("idx: %lu\n", i);
			node = ht->array[i];
			while (node)
			{
				printf("key: %s, value: %s\n", node->key, node->value);
				if (node->next)
					printf(" -> %s\n", node->next->key);
				else
					printf(" -> NULL\n\n");
				node = node->next;
			}
		}
	}
	return (EXIT_SUCCESS);
}
