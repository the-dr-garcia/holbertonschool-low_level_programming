#include "function_pointers.h"

/**
 * print_name - prints a name using a pointer to a function
 * @name: string to print
 * @f: pointer to the printing function
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}
