/**
 *
 * \brief Magic square formation challenge.
 *
 * https://www.hackerrank.com/challenges/magic-square-forming
 *
 * \details According to Wikipedia, only one unique magic square exists of side 3, formed by going right and up,
 * right and up, and left, in sequence, thrice. 8 trivially distinct matrices can be generated from a given matrix
 * by transposing and flipping the original. This program takes an input matrix, runs it through these transformations,
 * and determines the distance metric from the magic square for each. The minimum of these distance measurements is
 * taken as the final cost.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <bits/stdc++.h>

#define MAGIC_SQUARE_NUM_ROWS 3
#define MAGIC_SQUARE_ROW_SUM 15

using namespace std;

/**
 *
 * \brief Get the cost of changing the numbers to form a magic square.
 *
 * \details The sum of absolute differences of each number from the required magic square is computed.
 *
 * \param[in] input The input matrix.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int GetMagicSquareFormationCost(int input[MAGIC_SQUARE_NUM_ROWS][MAGIC_SQUARE_NUM_ROWS])
{
	int i;
	int sum = 0;

	int row = 1;
	int col = 2;

	for(i = 1; i <= (MAGIC_SQUARE_NUM_ROWS * MAGIC_SQUARE_NUM_ROWS); ++i)
	{
		sum += ((input[row][col] - i) > 0)? (input[row][col] - i): (i - input[row][col]);

		if(i % MAGIC_SQUARE_NUM_ROWS == 0)
		{
			// Go left.
			--col;

			if(col < 0)
			{
				col += MAGIC_SQUARE_NUM_ROWS;
			}
		}
		else
		{
			// Go right and up.
			--row;

			if(row < 0)
			{
				row += MAGIC_SQUARE_NUM_ROWS;
			}

			col = (col + 1) % MAGIC_SQUARE_NUM_ROWS;
		}
	}

	return sum;
}

/**
 *
 * \brief Flip the matrix about the middle row.
 *
 * \details Perform an in-situ flip of the given matrix.
 *
 * \param[in] input The input matrix.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
void FlipMatrix(int input[MAGIC_SQUARE_NUM_ROWS][MAGIC_SQUARE_NUM_ROWS])
{
	int i;
	int temp;

	for(i = 0; i < MAGIC_SQUARE_NUM_ROWS; ++i)
	{
		temp = input[0][i];
		input[0][i] = input[2][i];
		input[2][i] = temp;
	}
}

/**
 *
 * \brief Print the matrix.
 *
 * \param[in] input The input matrix.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
void PrintMatrix(int input[MAGIC_SQUARE_NUM_ROWS][MAGIC_SQUARE_NUM_ROWS])
{
	int i;
	int j;

	for(i = 0; i < MAGIC_SQUARE_NUM_ROWS; ++i)
	{
		for(j = 0; j < MAGIC_SQUARE_NUM_ROWS; ++j)
		{
			cout << input[i][j] << ",";
		}

		cout << endl;
	}
}

/**
 *
 * \brief Transpose the matrix in-situ.
 *
 * \param[in] input The input matrix.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
void TransposeMatrix(int input[MAGIC_SQUARE_NUM_ROWS][MAGIC_SQUARE_NUM_ROWS])
{
	int i;
	int j;
	int temp;

	for(i = 0; i < MAGIC_SQUARE_NUM_ROWS; ++i)
	{
		for(j = 0; j < i; ++j)
		{
			temp = input[i][j];
			input[i][j] = input[j][i];
			input[j][i] = temp;
		}
	}
}

int main()
{
	int i;
	int j;
	int min_sum = 100;
	int sum;

	int s[MAGIC_SQUARE_NUM_ROWS][MAGIC_SQUARE_NUM_ROWS];

	for(i = 0; i < MAGIC_SQUARE_NUM_ROWS; ++i)
	{
		for(j = 0; j < MAGIC_SQUARE_NUM_ROWS; ++j)
		{
			cin >> s[i][j];
		}
	}

	for(j = 0; j < 4; ++j)
	{
		TransposeMatrix(s);
		sum = GetMagicSquareFormationCost(s);
		min_sum = (sum < min_sum)? sum: min_sum;

		FlipMatrix(s);
		sum = GetMagicSquareFormationCost(s);
		min_sum = (sum < min_sum)? sum: min_sum;
	}

	cout << min_sum << endl;

	return 0;
}
