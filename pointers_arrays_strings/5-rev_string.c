#include "main.h"

/**
 * rev_string - Reverses a string.
 * @s: The pointer to the string to reverse.
 *
 * Return: Nothing.
 */
void rev_string(char *s)
{
	char tmp;
	int i, len = 0, half;

	/* Find the length of the string */
	while (s[len] != '\0')
	{
		len++;
	}

	half = len / 2;
	i = 0;
	len -= 1; /* Point to the last character */

	while (half > 0)
	{
		tmp = s[len];
		s[len] = s[i];
		s[i] = tmp;
		i++;
		len--;
		half--;
	}
}
