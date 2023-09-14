#ifndef VARIADIC_FUNCS
#define VARIADIC_FUNCS

#ifndef _STDARG_H_
#define _STDARG_H_
#include <stdarg.h>
#endif /* _STDARG_H_ */

typedef struct get_arg
{
	char *type;
	void (*f)(va_list);

} print_arg;

void print_char(va_list list);

void print_int(va_list list);

void print_float(va_list list);

void print_string(va_list list);

int sum_them_all(const unsigned int n, ...);

void print_numbers(const char *separator, const unsigned int n, ...);

void print_strings(const char *separator, const unsigned int n, ...);

void print_all(const char * const format, ...);

#endif /* VARIADIC_FUNCS */
