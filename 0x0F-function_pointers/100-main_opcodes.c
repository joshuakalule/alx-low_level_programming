#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	unsigned char *func_ptr = (char *)main;
	int i, arg;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	arg = atoi(argv[1]);

	if (arg < 0)
	{
		printf("Error\n");
		return (2);
	}

	for (i = 0; i < arg; i++)
	{
		printf("%02x", (unsigned char)func_ptr[i]);
		if (i != arg - 1)
			printf(" ");
	}
	printf("\n");

	return (0);
}
