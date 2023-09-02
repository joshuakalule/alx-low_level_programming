#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: integer less than, equal to, or greater than zero
 *         if s1 is found, respectively, to be less than,
 *         to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, retvalue;


	while (1)
	{
		retvalue = s1[i] - s2[i];

		if ((retvalue != 0) || (s1[i] == '\0') || (s2[i] == '\0'))
			break;
		i++;
	}
	return (retvalue);
}

