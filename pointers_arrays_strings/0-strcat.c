#include "main.h"

/**
 * _strcat - Appends the src string to the dest string.
 * @dest: The destination string.
 * @src: The source string to append.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	/* Move to the end of dest */
	while (dest[i] != '\0')
	{
		i++;
	}

	/* Copy src to dest starting from the null terminator position */
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* Add the terminating null byte */
	dest[i] = '\0';

	return (dest);
}
