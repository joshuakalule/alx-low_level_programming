#include <stdlib.h>

/**
 * size_of - recursively get the length of a string
 * @str: pointer to the string
 * @size: pointer to memory where size value is stored
 *
 * Return: length of the string
 */
int size_of(char *str, int *size)
{
	if (*str == '\0')
	{
		return (0);
	}
	else
	{
		(*size)++;
		return (size_of(str + 1, size));
	}
}

/**
 * palindrome - algorithm to find palindrome
 * @str: string
 * @i: iteration
 * @size: length of the string
 *
 * Return: 1 (True) or 0(False)
 */
int palindrome(char *str, int i, int size)
{
	if (i == size / 2)
	{
		if (size % 2 != 0)
		{
			if (str[i] == str[size - i])
				return (1);
			else
				return (0);
		}
		else
		{
			return (1);
		}
	}

	if (str[i] != str[size - i])
	{
		return (0);
	}
	else
	{
		return (palindrome(str, i + 1, size));
	}
}

/**
 * is_palindrome - check if str is a palindrome
 * @s: string to check
 *
 * Return: 1 (True) 0 (False)
 */
int is_palindrome(char *s)
{
	int n = 0;

	if (s == NULL)
		return (0);

	if (*s == '\0')
		return (1);

	size_of(s, &n);

	return (palindrome(s, 0, n - 1));
}
