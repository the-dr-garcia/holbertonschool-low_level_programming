#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int i = 0, j;
	char *sep = "";
	/* Define a struct to map chars to print logic */
	struct printer { char c; void (*f)(va_list); } funcs[] = {
		{'c', print_char}, {'i', print_int}, {'f', print_float}, {'s', print_str}
	};

	va_start(ap, format);
	while (format && format[i])
	{
		j = 0;
		while (j < 4 && format[i] != funcs[j].c)
			j++;
		if (j < 4) /* Only 1 if used here */
		{
			printf("%s", sep);
			funcs[j].f(ap);
			sep = ", ";
		}
		i++;
	}
	printf("\n");
	va_end(ap);
}
