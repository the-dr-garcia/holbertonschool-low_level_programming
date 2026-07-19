#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"

/**
 * is_number - checks if a string consists only of digits
 * @str: the string to check
 *
 * Return: 1 if all characters are digits, 0 otherwise
 */
int is_number(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

/**
 * main - adds positive numbers.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (Success), 1 (Error)
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	for (i = 1; i < argc; i++)
	{
		if (!is_number(argv[i]))
		{
			printf("Error\n");
			return (1);
		}
		sum += atoi(argv[i]);
	}
	printf("%d\n", sum);
	return (0);
}
