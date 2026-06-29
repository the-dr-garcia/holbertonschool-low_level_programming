#include "main.h"

/**
 * _islower - Checks for a lowercase character.
 * @c: The character to be checked in ASCII value.
 *
 * Return: 1 if c is lowercase, 0 otherwise.
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}
