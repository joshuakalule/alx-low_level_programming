#include <stdio.h>
#include <stdlib.h>
#include "variadic_functions.h"

void print_char(va_list list);

void print_int(va_list list);

void print_float(va_list list);

void print_string(va_list list);

/**
 * print_all - prints all arguments
 * @format: list of types of arguments
 */
void print_all(const char * const format, ...)
{
	va_list list;
	int i = 0, j = 0;

	print_arg args[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}
	};

	va_start(list, format);

	while (format && format[j])
	{
		i = 0;
		while (args[i].type)
		{
			if (args[i].type[0] == format[j])
			{
				(args[i].f)(list);
				if (format[j + 1])
					printf(", ");
			}
			i++;
		}
		j++;
	}
	putchar('\n');
	va_end(list);
}

/**
 * print_char - prints a character
 * @list: variable list
 */
void print_char(va_list list)
{
	printf("%c", va_arg(list, int));
}

/**
 * print_int - prints an integer
 * @list: variable list
 */
void print_int(va_list list)
{
	printf("%d", va_arg(list, int));
}

/**
 * print_float - prints a float
 * @list: variable list
 */
void print_float(va_list list)
{
	printf("%f", va_arg(list, double));
}

/**
 * print_string- prints a string
 * @list: variable list
 */
void print_string(va_list list)
{
	char *s = va_arg(list, char *);

	switch (!s)
	{
		case 0:
			printf("%s", s);
			break;
		case 1:
			printf("(nil)");
			break;
	}
}

