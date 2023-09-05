#include <stdlib.h>
#include "main.h"

/**
 * _strdup - get size of string
 * @str: string
 *
 * Return: pointer to new array
 *         NULL if str = NULL
 */
char *_strdup(char *str)
{
	unsigned int i;
	char *a;

	if (str == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		;
	a = malloc(sizeof(char) * (i + 1));

	if (a == 0)
		return (NULL);

	a[i] = '\0';
	while (i--)
	{
		a[i] = str[i];
	}
	return (a);
}
