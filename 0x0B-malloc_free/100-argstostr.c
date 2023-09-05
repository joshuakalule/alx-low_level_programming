#include <stdlib.h>
#include "main.h"

/**
 * argstostr - concatenates all the arguments of your program
 * @ac: number of arguments
 * @av: arguments
 *
 * Return: pointer to a new string
 *         NULL if fails
 */
char *argstostr(int ac, char **av)
{
	char *ptr, *tmp;
	int i, j, count = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		tmp = *(av + i);
		for (j = 0; tmp[j]; j++)
		{
			count++;
		}
		count += 1;
	}

	ptr = malloc(sizeof(char) * count + 1);

	if (ptr == 0)
		return (NULL);

	count = 0;
	for (i = 0; i < ac; i++)
	{
		tmp = *(av + i);
		for (j = 0; tmp[j]; j++)
		{
			ptr[count] = tmp[j];
			count++;
		}

		ptr[count] = '\n';
		count++;
	}
	ptr[count] = '\0';
	return (ptr);
}
