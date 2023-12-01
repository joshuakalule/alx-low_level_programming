#include "hash_tables.h"

/**
 * key_index - function that gives you the index of a key
 * @key: key to be hashed
 * @size: size of the array of the hash table
 *
 * Return: index at which the key/value pair should be stored
 * in the array of the hash table
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	if (!key || size == 0)
		return (0);
	return (hash_djb2(key) % size);
}
