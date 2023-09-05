#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * record_word - helper for main function
 * @p: pointer to array
 * @size: size of word
 * @str: pointer to source string
 * @i: pointer to index of character in str
 */
void record_word(char *p, int size, char *str, int *i)
{
	int n = 0;

	while (1)
	{
		if (n >= size)
			break;
		if (str[*i] == ' ')
		{
			*i += 1;
			continue;
		}
		p[n] = str[*i];
		n++;
		*i += 1;
	}
}

/**
 * get_size - helper for main function
 * @str: string
 * @k: iterator
 *
 * Return: size of one string
 */
int get_size(char *str, int *k)
{
	int prev = ' ';
	int tmp_size = 0;

	for (; str[*k] != '\0'; *k += 1)
	{
		if (prev != ' ' && str[*k] == ' ')
			break;
		if (str[*k] == ' ')
		{
			prev = str[*k];
			continue;
		}
		tmp_size++;
		prev = str[*k];
	}
	return (tmp_size);
}

/**
 * strtow - splits a string into words
 * @str: string
 *
 * Return: pointer to array
 *         NULL otherwise
 */
char **strtow(char *str)
{
	int j, size, i = 0, k = 0, words = 0;
	char prev = ' ';
	char **ptr;

	if (str == NULL || *str == '\0' || (*str == ' ' && *(str + 1) == '\0'))
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' '  && prev == ' ')
		{
			words++;
		}
		prev = str[i];
	}
	ptr = malloc(sizeof(*ptr) * (words + 1));
	ptr[words] = malloc(1);
	*ptr[words] = '\0';
	if (ptr == NULL)
		return (NULL);
	i = 0;
	for (j = 0; j < words; j++)
	{
		prev = ' ';
		size = get_size(str, &k);
		ptr[j] = malloc(sizeof(char) * (size + 1));
		if (ptr[j] == NULL)
		{
			while (j--)
			{
				free(ptr[j]);
			}
			free(ptr);
			return (NULL);
		}
		ptr[j][size] = '\0';
		record_word(ptr[j], size, str, &i);
	}
	return (ptr);
}
