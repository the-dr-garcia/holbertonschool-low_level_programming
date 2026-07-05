#include "main.h"

/**
 * print_rev - Prints a string in reverse, followed by a new line.
 * @s: The pointer to the string to print.
 *
 * Return: Nothing.
 */
void print_rev(char *s)
{
	int len = 0;

	/* Find the length of the string */
	while (s[len] != '\0')
	{
		len++;
	}

	/* Move backward from the last character to the first */
	for (len -= 1; len >= 0; len--)
	{
		_putchar(s[len]);
	}

	_putchar('\n');
}
