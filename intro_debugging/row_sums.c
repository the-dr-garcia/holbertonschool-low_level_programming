#include <stdio.h>

/**
 * row_sum - Computes the sum of a specific row.
 * @row: The row number.
 * @cols: The number of columns.
 *
 * Return: The sum of the current row.
 */
int row_sum(int row, int cols)
{
	int c;
	int sum = 0;

	for (c = 1; c <= cols; c++)
		sum += row * c;

	return (sum);
}

/**
 * total_sum - Computes the sum of all rows.
 * @rows: Number of rows.
 * @cols: Number of columns.
 *
 * Return: The total sum.
 */
int total_sum(int rows, int cols)
{
	int r;
	int total = 0;

	for (r = 1; r <= rows; r++)
	{
		total += row_sum(r, cols);
	}

	return (total);
}

/* -- DO NOT Modify the code below this line -- */
int main(void)
{
	printf("%d\n", total_sum(3, 3));
	return (0);
}
