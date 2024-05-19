#include "main.h"

int findchar(char *c, char *s);

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to check
 * @accept: bytes to be counted
 *
 * Return: number of bytes in the initial segment of @s which
 *         consist only of bytes from @accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i;
	unsigned int len = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (findchar((s + i), accept))
		{
			len++;
		}
		else if (len > 0)
		{
			return (len);
		}
	}
	return (len);
}

/**
 * findchar - checks if char 'c' occurs in string 's'
 * @c: character to look for
 * @s: string to scan
 * Return: 1 (found)
 *         0 (not found)
 */
int findchar(char *c, char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (*c == s[i])
		{
			return (1);
		}
	}
	return (0);
}
