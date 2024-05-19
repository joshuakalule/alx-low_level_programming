#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * set_string - sets the value of a pointer to a char
 * @s: pointer to a pointer
 * @to: character
 */
void set_string(char **s, char *to)
{
	size_t i, len;

	if (!s || !to)
		return;
	for (i = 0; to[i] != '\0'; i++)
		;
	len = i + 1;

	*s = malloc(sizeof(char) * len);
	if (*s == NULL)
		return;
	memcpy(*s, to, len - 1);
}
