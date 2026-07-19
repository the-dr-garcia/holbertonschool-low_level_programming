#include "variadic_functions.h"
#include <stdio.h>

/**
 * p_char - prints a char
 * @ap: argument list
 */
void p_char(va_list ap)
{
	printf("%c", va_arg(ap, int));
}

/**
 * p_int - prints an int
 * @ap: argument list
 */
void p_int(va_list ap)
{
	printf("%d", va_arg(ap, int));
}

/**
 * p_float - prints a float
 * @ap: argument list
 */
void p_float(va_list ap)
{
	printf("%f", va_arg(ap, double));
}

/**
 * p_str - prints a string
 * @ap: argument list
 */
void p_str(va_list ap)
{
	char *s = va_arg(ap, char *);

	s || (s = "(nil)");
	printf("%s", s);
}

/**
 * print_all - prints anything
 * @format: list of types
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int i = 0, j;
	char *sep = "";
	struct printer
	{
		char c;
		void (*f)(va_list);
	} funcs[] = {
		{'c', p_char}, {'i', p_int}, {'f', p_float}, {'s', p_str}
	};

	va_start(ap, format);
	while (format && format[i])
	{
		j = 0;
		while (j < 4 && format[i] != funcs[j].c)
			j++;
		if (j < 4)
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
