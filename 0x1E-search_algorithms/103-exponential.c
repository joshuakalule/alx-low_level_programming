#include "search_algos.h"

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
 * _binary_search - function for binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @low: position of lower bound
 * @high: position of higher bound
 * @value: value to search for
 *
 * Return: answer
 */

int _binary_search(int *array, size_t low, size_t high, int value)
{
	size_t mid, i;

	if (array == NULL || low > high)
		return (-1);

	mid = low + ((high - low) / 2);

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i != high)
			printf(", ");
	}
	printf("\n");

	if (array[mid] == value)
		return (mid);

	if (array[mid] < value)
		return (_binary_search(array, mid + 1, high, value));
	else
		return (_binary_search(array, low, mid - 1, value));

	return (-1);
}

/**
 * exponential_search - Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i, high, low;

	if (array == NULL)
		return (-1);

	if (array[0] == value)
		return (0);

	for (i = 1;; i *= 2)
	{
		if (i >= size || array[i] >= value)
		{
			low = i / 2;
			high = min(i, size - 1);
			printf("Value found between indexes [%ld] and [%ld]\n", low, high);
			return (_binary_search(array, low, high, value));
		}
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}
	return (-1);
}
