#include "search_algos.h"

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
		return (mid);

	if (array[mid] < value)
		return (helper(array, mid + 1, high, value));
	else
		return (helper(array, low, mid - 1, value));

	return (-1);
}

/**
 * binary_search - Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: position or -1 (FAIL)
 */
int binary_search(int *array, size_t size, int value)
{
	int answer;

	answer = helper(array, 0, size - 1, value);

	return (answer);
}
