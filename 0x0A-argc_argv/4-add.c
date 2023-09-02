#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - prints program name
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	int ch, i, sum = 0;

	if (argc < 2)
	{
		printf("0\n");
		return (0);
	}
	else
	{
		for (i = 1; i < argc; i++)
		{
			for (ch = 0; argv[i][ch] != '\0'; ch++)
			{
				if (!isdigit(argv[i][ch]))
				{
					printf("Error\n");
					return (1);
				}
			}
			sum += atoi(argv[i]);
		}
	}
	printf("%d\n", sum);
	return (0);
}
