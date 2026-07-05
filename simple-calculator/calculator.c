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
 * div_op - Divides two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: The result of a / b as a float.
 */
float div_op(int a, int b)
{
	return ((float)a / (float)b);
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
		else if (choice >= 1 && choice <= 4)
		{
			printf("A: ");
			scanf("%d", &a);
			printf("B: ");
			scanf("%d", &b);

			if (choice == 1)
				printf("Result: %d\n", add(a, b));
			else if (choice == 2)
				printf("Result: %d\n", sub(a, b));
			else if (choice == 3)
				printf("Result: %d\n", mul(a, b));
			else
			{
				if (b == 0)
					printf("Error: division by zero\n");
				else
					printf("Result: %.1f\n", div_op(a, b));
			}
		}
		else
		{
			printf("Invalid choice\n");
		}
	}
	return (0);
}
