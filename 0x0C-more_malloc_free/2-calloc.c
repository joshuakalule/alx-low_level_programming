#include <stdlib.h>
#include <string.h>

/**
 * _calloc - allocates memory for an array
 * @nmemb: number of elements in array
 * @size: size of each element
 *
 * Return: pointer to allocated memory
 *         NULL otherwise
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(size * nmemb);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size);  i++)
	{
		ptr[i] = 0;
	}
	return ((void *)ptr);
}
