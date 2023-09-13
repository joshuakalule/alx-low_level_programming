#include <stdio.h>
#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: to search in
 * @size: of the array
 * @cmp: function pointer
 *
 * Return: index of the first element found
 *         - 1 (Otherwise)
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (!array || !size || !cmp)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
