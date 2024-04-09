#include "search_algos.h"

/**
 * helper - helper function for interpolation_search
 * @array: pointer to the first element of the array to search in
 * @low: position at lower bound
 * @high: position at higher bound
 * @value: value to search for
 *
 * Return: first index where value is located
 */
int helper(int *array, size_t low, size_t high, int value)
{
	size_t pos;
	double x;

	if (array == NULL || low > high)
		return (-1);

	x = ((double)(high - low) / (array[high] - array[low]));
	pos = low + (x * (value - array[low]));

	if (pos > high)
	{
		printf("Value checked array[%ld] is out of range\n", pos);
		return (-1);
	}

	printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
	if (array[pos] == value)
		return (pos);

	return (helper(array, pos + 1, high, value));
}

/**
 * interpolation_search - Interpolation search
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located
 */
int interpolation_search(int *array, size_t size, int value)
{
	return (helper(array, 0, size - 1, value));
}
