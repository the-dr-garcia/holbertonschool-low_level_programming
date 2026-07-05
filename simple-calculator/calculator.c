#include <stdio.h>

/**
 * main - Entry point for the calculator.
 *
 * Return: Always 0.
 */
int main(void)
{
	int choice;

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
			/* Clear buffer if non-integer input is provided */
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
			/* Placeholder for future operations */
		}
		else
		{
			printf("Invalid choice\n");
		}
	}

	return (0);
}
