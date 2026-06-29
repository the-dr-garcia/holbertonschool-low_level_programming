#include <stdio.h>

/**
 * sum_to_n - Computes the sum of all integers from 1 to n.
 * @n: The upper limit integer.
 *
 * Return: The sum of integers from 1 to n.
 */
int sum_to_n(int n)
{
	int i;
	int sum = 0;

	for (i = 1; i <= n; i++)
	{
		sum += i;
	}

	return (sum);
}

/* -- DO NOT Modify the code below this line -- */
int main(void)
{
	printf("%d\n", sum_to_n(10));
	return (0);
}
