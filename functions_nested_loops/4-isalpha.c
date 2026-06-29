#include "main.h"

/**
 * _isalpha - Checks for an alphabetic character.
 * @c: The character to be checked in ASCII value.
 *
 * Return: 1 if c is a letter (lowercase or uppercase), 0 otherwise.
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}
