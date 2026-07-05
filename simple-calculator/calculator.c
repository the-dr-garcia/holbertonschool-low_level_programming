#include <stdio.h>

/**
 * main - Entry point for the calculator.
 *
 * Return: Always 0.
 */
int main(void)
{
	int choice;

	printf("Simple Calculator\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");

	while (1)
	{
		printf("Choice: ");
		if (scanf("%d", &choice) != 1)
		{
			/* Handle non-integer input if necessary */
			break;
		}

		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}
		else if (choice >= 1 && choice <= 4)
		{
			printf("Operation %d selected (not yet implemented).\n", choice);
		}
		else
		{
			printf("Invalid choice.\n");
		}
	}

	return (0);
}
