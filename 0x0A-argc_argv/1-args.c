#include <stdio.h>

/**
 * main - prints program name
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	(void) argv;

	if (argc > 1)
	{
		printf("%d\n", argc - 1);
	}
	else
	{
		printf("%d\n", 0);
	}
	return (0);
}
