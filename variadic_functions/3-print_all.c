#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int i = 0, j = 0;
	char *sep = "";
	char *str;

	va_start(ap, format);
	while (format && format[i])
	{
		j = 0;
		while (j < 4 && format[i] != "cifs"[j])
			j++;
		if (j < 4)
		{
			printf("%s", sep);
			if (j == 0) printf("%c", va_arg(ap, int));
			if (j == 1) printf("%d", va_arg(ap, int));
			if (j == 2) printf("%f", va_arg(ap, double));
			if (j == 3)
			{
				str = va_arg(ap, char *);
				if (!str) str = "(nil)";
				printf("%s", str);
			}
			sep = ", ";
		}
		i++;
	}
	printf("\n");
	va_end(ap);
}
