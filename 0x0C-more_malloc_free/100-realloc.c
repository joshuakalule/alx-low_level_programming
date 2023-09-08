#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with malloc
 * @old_size: old size allocated to ptr
 * @new_size: new size to be allocated
 *
 * Return: pointer (ptr)
 *         NULL otherwise
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i = 0;
	char *p0 = ptr, *p1;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && p0 != NULL)
	{
		free(ptr);
		return (NULL);
	}

	p1 = malloc(new_size);

	if (p1 == NULL)
		return (NULL);

	if (p0 != NULL)
	{
		for (; i < old_size; i++)
		{
			p1[i] = p0[i];
		}
	}

	for (; i < new_size; i++)
	{
		p1[i] = 0;
	}
	free(ptr);
	return ((void *) p1);
}
