#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * get_word_count - number of words in the string
 * @str: string
 *
 * Return: number of words in the string
 */
int get_word_count(char *str)
{
	int i, count = 0;
	int word = 0;

	for (i = 0; ; i++)
	{
		if (str[i] == '\0')
		{
			if (word == 1)
				count += 1;
			break;
		}
		else if (str[i] == ' ')
		{
			if (word == 1)
			{
				count += 1;
				word = 0;
			}
		}
		else
		{
			word = 1;
		}
	}
	return (count);
}

/**
 * add_word - adds a word to the words array
 * @buffer: current word in the buffer to be added to the array
 * @size: size of the word in the buffer
 * @array: array
 * @words: number of words in the array
 *
 * Return: 0 (Success) 1 (Fail)
 */
int add_word(char *buffer, size_t size, char **array, int *words)
{
	char *ptr;

	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (1);

	memcpy(ptr, buffer, size);
	ptr[size] = '\0';

	array[*words] = ptr;
	*words += 1;
	return (0);
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
	char **words;
	int i, x, word_count;
	char buffer[1024] = {'\0'};

	if (str == NULL || str[0] == '\0')
		return (NULL);

	x = get_word_count(str);
	if (x == 0)
		return (NULL);
	words = malloc(sizeof(words) * (x + 1));
	if (words == NULL)
		return (NULL);
	words[x] = NULL;

	word_count = 0;
	x = 0;
	for (i = 0;; i++)
	{
		if (str[i] != ' ' && str[i] != '\0')
		{
			buffer[x++] = str[i];
		}
		else
		{
			if (buffer[0] != '\0')
			{
				if (add_word(buffer, x, words, &word_count) != 0)
					return (NULL);
				/* reset buffer */
				memset(buffer, 0, x);
				x = 0;
			}
			/* termiantion case */
			if (str[i] == '\0')
				break;
		}
	}
	return (words);
}
