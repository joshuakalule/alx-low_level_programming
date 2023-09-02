#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: string to check
 * @c: character being looked for
 *
 * Return: pointer to the first occurance of c
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (c == s[i])
		{
			return ((s + i));
		}
	}
	if (c == '\0')
		return ((s + i));
	return ('\0');
}
