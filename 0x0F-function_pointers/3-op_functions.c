#include "3-calc.h"

/**
 * op_add - adds
 * @a: integer 1
 * @b: integer 2
 * Return: sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtracts
 * @a: integer 1
 * @b: integer 2
 * Return: difference of a and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplies
 * @a: integer 1
 * @b: integer 2
 * Return: multiple of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divides
 * @a: integer 1
 * @b: integer 2
 * Return: result of division of a by b
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - returns the remainder of division
 * @a: integer 1
 * @b: integer 2
 * Return: remainder of division of a by b
 */
int op_mod(int a, int b)
{
	return (a % b);
}
