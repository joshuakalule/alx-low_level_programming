#include "search_algos.h"

/**
 * find - finds the first occurance of value
 * @array: pointer to the first element of the array to search in
 * @idx: pos of value
 * @value: value whose first occurance we are looking for
 *
 * Return: index of first occurance
 */
int find(int *array, int idx, int value)
{
	if (array == NULL || idx < 0)
		return (idx);

	if (array[idx - 1] != value)
		return (idx);
	else
		return (find(array, idx - 1, value));
}


/**
 * helper - helper function for binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @low: position of lower bound
 * @high: position of higher bound
 * @value: value to search for
 *
 * Return: answer
 */

int helper(int *array, size_t low, size_t high, int value)
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
		return (find(array, mid, value));

	if (array[mid] < value)
		return (helper(array, mid + 1, high, value));
	else
		return (helper(array, low, mid - 1, value));

	return (-1);
}

/**
 * advanced_binary - Advanced binary search
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	return (helper(array, 0, size - 1, value));
}
