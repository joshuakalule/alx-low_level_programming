#include "main.h"

/**
 * print_rev -  prints a string, in reverse, followed by a new line
 * @s: string
 */
void print_rev(char *s)
{
	int count = 0, i;

	while (s[count] != '\0')
	{
		count++;
	}

	i = count - 1;
	while (i >= 0)
	{
		_putchar(s[i]);
		i--;
	}
	_putchar('\n');
}

