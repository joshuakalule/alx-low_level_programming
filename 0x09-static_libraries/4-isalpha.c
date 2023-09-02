#include "main.h"

/**
 * _isalpha - checks for alphabetic character
 * @c: character value to be checked
 *
 * Return: 1 if a letter, lowercase or uppercase
 *	   0 otherwise
 */
int _isalpha(int c)
{
	if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)))
	{
		return (1);
	}
	return (0);
}
