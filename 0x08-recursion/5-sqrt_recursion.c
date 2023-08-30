#include "main.h"

int helper(int n, int i);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: integer
 *
 * Return: natural square root of a n
 */
int _sqrt_recursion(int n)
{
	if (n == 1)
		return (1);

	return (helper(n, n / 2));
}

/**
 * helper - helps get the sqrt
 * @n: the number whose sqrt we want
 * @i: iterator
 *
 * Return: sqrt(n)
 *         -1 if n <= 0
 */
int helper(int n, int i)
{
	if (i <= 0)
		return (-1);
	if (i * i == n)
		return (i);

	return (helper(n, i - 1));
}
