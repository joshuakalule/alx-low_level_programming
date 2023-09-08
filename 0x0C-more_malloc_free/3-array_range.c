#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * array_range - create an array of integers
 * @min: min element
 * @max: max element
 *
 * Return: pointer to the newly created array
 */
int *array_range(int min, int max)
{
	int i, j = min;
	int *ptr;

	if (min > max)
		return (NULL);

	ptr = malloc(sizeof(int) * (max - min + 1));

	if (ptr == NULL)
		return (NULL);

	for (i = 0; j <= max; i++, j++)
	{
		ptr[i] = j;
	}
	return (ptr);
}
