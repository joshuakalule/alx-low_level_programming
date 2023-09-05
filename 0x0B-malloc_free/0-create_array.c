#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars,
 *                and initializes it with a specific char
 * @size: size of array
 * @c: character to initialize in the array
 *
 * Return: pointer to array
 *         NULL if size = 0 or fails
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *ar = malloc(size);

	if (size == 0 || ar == 0)
		return (0);
	for (i = 0; i < size; i++)
	{
		ar[i] = c;
	}
	return (ar);
}
