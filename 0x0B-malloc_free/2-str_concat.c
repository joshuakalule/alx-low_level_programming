#include <stdlib.h>
#include "main.h"

/**
 * str_concat - concatenates two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: pointer to new location
 *         NULL if failed
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int i = 0, j = 0, ij;
	char *a;

	if (s1 != NULL)
	{
		for (; s1[i] != '\0'; i++)
		;
	}

	if (s2 != NULL)
	{
		for (; s2[j] != '\0'; j++)
		;
	}

	ij = i + j;

	a = malloc(sizeof(char) * (ij + 1));

	if (a == NULL)
		return (NULL);

	a[ij] = '\0';
	ij--;

	while (j--)
	{
		a[ij] = s2[j];
		ij--;
	}
	while (i--)
	{
		a[ij] = s1[i];
		ij--;
	}
	return (a);
}
