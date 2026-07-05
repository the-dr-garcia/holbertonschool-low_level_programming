#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The pointer to the string.
 *
 * Return: A pointer to the modified string.
 */
char *cap_string(char *str)
{
	int i, j;
	char sep[] = " \t\n,;.!?\"(){}";

	for (i = 0; str[i] != '\0'; i++)
	{
		/* Check if we are at the first character of the string */
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;

		/* Check for separators */
		for (j = 0; sep[j] != '\0'; j++)
		{
			if (str[i] == sep[j])
			{
				if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
					str[i + 1] -= 32;
			}
		}
	}

	return (str);
}
