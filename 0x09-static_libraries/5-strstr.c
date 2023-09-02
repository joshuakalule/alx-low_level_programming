#include "main.h"

int findchar(char *c, char *s);

/**
 * _strstr - locates a substring
 * @haystack: string to scan
 * @needle: string to locate
 * Return: pointer to the beginning of the located substring
 *         NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j = 0;
	char *ptr = '\0';

	if (needle[j] == '\0')
		return (haystack);
	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (needle[j] == '\0')
		{
			break;
		}
		if (haystack[i] == needle[j])
		{
			if (ptr == 0x0)
			{
				ptr = (haystack + i);
			}
			j++;
		}
		else if (j > 0)
		{
			j = 0;
			ptr = '\0';
		}
	}
	if (needle[j] != '\0')
		return ('\0');
	return (ptr);
}
