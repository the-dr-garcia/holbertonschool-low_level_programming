#include "main.h"

int check_sqrt(int n, int i);

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to find the square root of.
 *
 * Return: The natural square root, or -1 if none exists.
 */
int _sqrt_recursion(int n)
{
	return (check_sqrt(n, 1));
}

/**
 * check_sqrt - Helper function to check for the natural square root.
 * @n: The number to check.
 * @i: The current iterator/guess.
 *
 * Return: The square root, or -1 if none exists.
 */
int check_sqrt(int n, int i)
{
	if (i * i > n)
	{
		return (-1);
	}
	if (i * i == n)
	{
		return (i);
	}
	return (check_sqrt(n, i + 1));
}
