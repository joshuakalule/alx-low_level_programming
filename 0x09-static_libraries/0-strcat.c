#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: string to be modified
 * @src: string to be added to dest
 *
 * Return: pointer to dest
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (*(dest + i) != '\0')
	{
		i++;
	}

	while (*(src + j) != '\0')
	{
		dest[j + i] = src[j];
		j++;
	}
	dest[j + i] = '\0';

	return (dest);
}
