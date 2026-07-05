#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The pointer to the string.
 *
 * Return: The integer converted from the string.
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, flag = 0;
	unsigned int res = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			sign *= 1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			res = res * 10 + (s[i] - '0');
		}
		else if (flag)
			break;
		i++;
	}

	return (res * sign);
}
