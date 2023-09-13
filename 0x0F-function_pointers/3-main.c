#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

#ifndef CONSTANTS
#define CONSTANTS
#define OP(x) (argv[2][0] == x)
#endif /* CONSTANTS */

/**
 * main - entry point
 * @argc: number of arguments passed
 * @argv: array of arguments
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	int result;
	int a;
	int b;
	char *op;

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	op = argv[2];

	if ((OP('/') || OP('%')) && b == 0)
	{
		printf("Error\n");
		return (100);
	}

	if (!(get_op_func(op)))
	{
		printf("Error\n");
		return (99);
	}

	result = (get_op_func(op))(a, b);

	printf("%d\n", result);

	return (0);
}
