#include "main.h"
#include <stddef.h>

/**
 * _strchr - Locates a character in a string.
 * @s: The string to search.
 * @c: The character to locate.
 *
 * Return: A pointer to the first occurrence of c, or NULL if not found.
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] >= '\0')
	{
		if (s[i] == c)
		{
			return (s + i);
		}
		if (s[i] == '\0')
		{
			break;
		}
		i++;
	}

	return (NULL);
}
