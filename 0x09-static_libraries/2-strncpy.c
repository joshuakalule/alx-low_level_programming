#include "main.h"

/**
 * _strncpy - copies a string
 * @dest: string to be modified
 * @src: string to be appended
 * @n: number of characters to copy
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while ((i < n) && (src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{

		dest[i] = '\0';
		i++;
	}

	return (dest);
}
