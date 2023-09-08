#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * min - minimum of 2 integers
 * @a: integer 1
 * @b: integer 2
 * Return: minimum integer
 */
unsigned long min(unsigned long a, unsigned long b)
{
	return ((a > b) ? b : a);
}

/**
 * max - maximum of 2 integers
 * @a: integer 1
 * @b: integer 2
 * Return: maximum integer
 */
unsigned long max(unsigned long a, unsigned long b)
{
	return ((a < b) ? b : a);
}

/**
 * num - convert number to char
 * @a: character
 * Return: number form of char a
 */
int num(char a)
{
	return ((int)a - 48);
}

/**
 * sum_arrays - adds up the numbers in array
 * @ptr: pointer to array
 * @size: number of numbers to add
 * @other_size: number of characters in each array
 * Return: pointer to array with answer
 */
char *sum_arrays(char **ptr, unsigned long size, unsigned long other_size)
{
	unsigned long i, j, k, x, sum, carry = 0, len = (size + other_size);
	unsigned long y;
	char *answer = malloc(len);

	if (answer == NULL)
		return (NULL);
	answer[len - 1] = '\0';

	for (i = (len - 1), k = strlen(ptr[0]) - 1; i + 1; i--, k--)
	{
		sum = 0;
		for (x = 0, j = size - 1; j + 1; j--, x++)
		{
			y = k + x;
			if (y >= strlen(ptr[j]))
				continue;
			else
				sum += ptr[j][y] - 48;
		}
		sum += carry;
		carry = sum / 10;
		answer[i] = (sum % 10) + 48;
	}
	return (answer);
}

/**
 * check - checks if all characters are numbers
 * @a: pointer to array containing number
 * Return: 0 (Succcess)
 *         1 (Otherwise)
 */
int check(char *a)
{
	unsigned long i;

	for (i = 0; i < strlen(a); i++)
	{
		if (a[i] < '0' || a[i] > '9')
			return (1);
	}
	return (0);
}

/**
 * print_ans - prints answer
 * @ans: answer
 */
void print_ans(char *ans)
{
	unsigned long i = 0;

	if (ans[i] != '0')
		putchar(ans[i]);

	for (i = 0; i < strlen(ans); i++)
	{
		if (i == 0)
			continue;
		putchar(ans[i]);
	}
	putchar('\n');
}

/**
 * main - entry point
 * @argc: number of arguments passed
 * @argv: array of arguments
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	unsigned long i, j, k, ans, m, carry = 0;
	unsigned long m1, m2;
	char *p1, *p2, *mul;
	char **final;

	if (argc != 3 || check(argv[1]) == 1 || check(argv[2]) == 1)
	{
		printf("Error\n");
		return (98);
	}
	m1 = min(strlen(argv[1]), strlen(argv[2]));
	m2 = max(strlen(argv[1]), strlen(argv[2]));
	final = malloc(m1);

	if (m1 == strlen(argv[1]))
	{
		p1 = argv[2];
		p2 = argv[1];
	}
	else
	{
		p1 = argv[1];
		p2 = argv[2];
	}
	for (i = m1 - 1; i + 1; i--)
	{
		final[i] = malloc(m2 + 2);
		final[i][m2 + 1] = '\0';
		for (j = m2 - 1, k = j + 1; j + 1; j--, k--)
		{
			m = num(p2[i]) * num(p1[j]) + carry;
			carry = m / 10;
			ans = m % 10;
			final[i][k] = ans + 48;
		}
		final[i][k] = carry + 48;
	}
	mul = sum_arrays(final, m1, m2);
	print_ans(mul);
	return (0);
}
