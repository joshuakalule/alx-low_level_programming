#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string pointer
 *
 * Return: length of string 's'
 */

int _strlen(char *s)
{
	int a;
	int count = 0;

	do {
		a = s[count];
		count++;
	} while (a != '\0');

	count--;
	return (count);
}


