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
	*s = to;
}
