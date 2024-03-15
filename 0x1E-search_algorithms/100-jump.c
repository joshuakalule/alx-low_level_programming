#include "search_algos.h"
#include <math.h>
/**
 * min - get minimum
 * @a: number 1
 * @b: number 2
 *
 * Return: min
 */
size_t min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

/**
 * jump_search - Jump search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, m, j;

	if (array == NULL)
		return (-1);

	m = sqrt(size);
	for (i = 0;; i += m)
	{
		if (i >= size || array[i] >= value)
		{
			printf("Value found between indexes [%ld] and [%ld]\n", i - m, i);

			for (j = i - m; j < min(i + 1, size); j++)
			{
				printf("Value checked array[%ld] = [%d]\n", j, array[j]);
				if (array[j] == value)
					return (j);
			}
			return (-1);
		}
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}
	return (-1);
}
