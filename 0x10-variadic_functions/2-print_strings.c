#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - prints strings
 * @separator: string to separate prints
 * @n: number of strings
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list list;
	unsigned int i;
	char *arg;

	va_start(list, n);

	for (i = 0; i < n; i++)
	{
		arg = va_arg(list, char *);
		if (arg)
			printf("%s", arg);
		else
			printf("(nil)");

		if (i != n - 1 && separator)
			printf("%s", separator);
	}
	putchar('\n');
	va_end(list);
}
