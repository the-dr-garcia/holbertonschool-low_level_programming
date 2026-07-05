#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @s: The pointer to the string.
 *
 * Return: The length of the string as an integer.
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	return (length);
}
