#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

void print_sep(const char *sep);

/**
 * print_numbers - prints numbers
 * @separator: string to be printed between numbers
 * @n:  number of integers passed to the function
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list list;
	unsigned int i;

	va_start(list, n);
	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(list, int));

		if (i != n - 1)
			print_sep(separator);
	}
	putchar('\n');
	va_end(list);
}

/**
 * print_sep - prints the separator
 * @sep: pointer to the string
 */
void print_sep(const char *sep)
{
	int i;

	if (sep == NULL)
		return;

	for (i = 0; sep[i] != '\0'; i++)
		putchar(sep[i]);
}

