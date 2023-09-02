#include "main.h"

/**
 * _strncat - concatenates two strings
 * @dest: string to be modifed
 * @src: string to be added to dest
 * @n: nuber of elements to append
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	while (*(dest + i) != '\0')
	{
		i++;
	}


	while ((j < n) && (src[j] != '\0'))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[j + i] = '\0';
	return (dest);
}
