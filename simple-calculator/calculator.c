#include <stdio.h>

/**
 * add - Adds two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: The sum of a and b.
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - Subtracts two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: The result of a - b.
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - Multiplies two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: The result of a * b.
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 * main - Entry point for the calculator.
 *
 * Return: Always 0.
 */
int main(void)
{
	int choice, a, b;

	while (1)
	{
		printf("Simple Calculator\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");

		if (scanf("%d", &choice) != 1)
		{
			while (getchar() != '\n')
				;
			printf("Invalid choice\n");
			continue;
		}

		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}
		else if (choice >= 1 && choice <= 3)
		{
			printf("A: ");
			scanf("%d", &a);
			printf("B: ");
			scanf("%d", &b);
			if (choice == 1)
				printf("Result: %d\n", add(a, b));
			else if (choice == 2)
				printf("Result: %d\n", sub(a, b));
			else
				printf("Result: %d\n", mul(a, b));
		}
		else if (choice == 4)
		{
			/* Placeholder for division */
		}
		else
		{
			printf("Invalid choice\n");
		}
	}
	return (0);
}
