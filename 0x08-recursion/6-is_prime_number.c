#include "main.h"

int find_prime(int n, int i);

/**
 * is_prime_number - checks if a number is prime
 * @n: integer to be checked
 *
 * Return: 1 if the input integer is a prime number
 *         0 Otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (find_prime(n, n - 1));
}

/**
 * find_prime - helper function
 * @n: number to check
 * @i: iterator to keep checking
 *
 * Return: 1 if Prime else 0
 */
int find_prime(int n, int i)
{
	if (i == 1)
		return (1);
	else if (n % i == 0)
		return (0);
	else if (n % i != 0)
		return (find_prime(n, i - 1));
	return (0);
}
