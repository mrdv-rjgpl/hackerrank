#include <bits/stdc++.h>

#define MAGIC_SQUARE_NUM_ROWS 3
#define MAGIC_SQUARE_ROW_SUM 15

using namespace std;

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
			--col;

			if(col < 0)
			{
				col += MAGIC_SQUARE_NUM_ROWS;
			}
		}
		else
		{
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
