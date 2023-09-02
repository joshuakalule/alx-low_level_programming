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
	while (argc--)
	{
		printf("%s\n", *argv++);
	}
	return (0);
}
