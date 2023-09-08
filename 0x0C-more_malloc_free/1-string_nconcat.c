#include <stdlib.h>
#include "main.h"
#include <string.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: string 1
 * @s2: string 2
 * @n: bytes in s2 that should be concatenated to s1
 *
 * Return: pointer to newly allocated space
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	unsigned int i = 0, j = 0, s1len, s2len;

	if (s1 != NULL)
		s1len = strlen(s1);
	else
		s1len = 0;
	if (s2 != NULL)
	{
		if (n > strlen(s2))
			s2len = strlen(s2);
		else
			s2len = n;
	}
	else
	{
		s2len = 0;
	}
	ptr = malloc(sizeof(char) * (s1len + s2len + 1));
	if (ptr == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		for (; s1[i] != '\0'; i++)
		{
			ptr[i] = s1[i];
		}
	}
	if (s2 != NULL)
	{
		for (; j < s2len; j++, i++)
		{
			ptr[i] = s2[j];
		}
	}
	ptr[i] = '\0';
	return (ptr);
}
