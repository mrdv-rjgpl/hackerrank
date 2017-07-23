#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

class BomberMan
{
	private:
		bool add_bombs;
		int **bombing_grid;
		int num_rows;
		int num_columns;

	public:
		BomberMan(int r, int c);
		void AddBombs(void);
		void Decrement(void);
		void Detonate(int m, int n);
		void Initialize(void);
		void Propagate(void);
		string str(void);
};

/**
 *
 * \brief Create a new BomberMan object with 'r' rows and 'c' columns.
 *
 * \param[in] r The number of rows in the matrix.
 * \param[in] c The number of columns in the matrix.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
BomberMan::BomberMan(int r, int c)
{
	int i;

	this->add_bombs = false;
	this->num_rows = r;
	this->num_columns = c;
	this->bombing_grid = (int **) malloc(r * sizeof(int *));

	for(i = 0; i < r; ++i)
	{
		this->bombing_grid[i] = (int *) malloc(c * sizeof(int));
	}
}

/**
 *
 * \brief Add bombs in empty cells.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
void BomberMan::AddBombs(void)
{
	int i;
	int j;

	for(i = 0; i < this->num_rows; ++i)
	{
		for(j = 0; j < this->num_columns; ++j)
		{
			if(this->bombing_grid[i][j] == 0)
			{
				this->bombing_grid[i][j] = 3;
			}
		}
	}
}

/**
 *
 * \brief Decrement the counters on the bombs, and detonate any bombs that need to be detonated.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
void BomberMan::Decrement(void)
{
	int i;
	int j;

	for(i = 0; i < this->num_rows; ++i)
	{
		for(j = 0; j < this->num_columns; ++j)
		{
			if(this->bombing_grid[i][j] == 1)
			{
				this->Detonate(i, j);
			}
			else if(this->bombing_grid[i][j] > 1)
			{
				--this->bombing_grid[i][j];
			}
		}
	}
}

/**
 *
 * \brief Detonate the given position.
 *
 * Assume that this function is only called from decrement, so leave the cells below and to the right untouched,
 * if they need to be detonated.
 *
 * \param[in] m The row index of the position to be detonated.
 * \param[in] n The column index of the position to be detonated.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
void BomberMan::Detonate(int m, int n)
{
	this->bombing_grid[m][n] = 0;

	if(m - 1 >= 0)
	{
		this->bombing_grid[m - 1][n] = 0;
	}

	if(n - 1 >= 0)
	{
		this->bombing_grid[m][n - 1] = 0;
	}

	if((m + 1 < this->num_rows) && (this->bombing_grid[m + 1][n] != 1))
	{
		this->bombing_grid[m + 1][n] = 0;
	}

	if((n + 1 < this->num_columns) && (this->bombing_grid[m][n + 1] != 1))
	{
		this->bombing_grid[m][n + 1] = 0;
	}
}

/**
 *
 * \brief Initialize the bombing grid.
 *
 * Source the bomb positions from stdin.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
void BomberMan::Initialize(void)
{
	char c;
	int i;
	int j;

	for(i = 0; i < this->num_rows; ++i)
	{
		for(j = 0; j < this->num_columns; ++j)
		{
			cin >> c;

			if(c == '.')
			{
				this->bombing_grid[i][j] = 0;
			}
			else if(c == 'O')
			{
				this->bombing_grid[i][j] = 3;
			}
			else
			{
				--j;
			}
		}
	}
}

/**
 *
 * \brief Propagate the system from one time step to the next.
 *
 * It is not made clear if the bomb addition is done before or after the bomb detonation.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
void BomberMan::Propagate(void)
{
	this->Decrement();

	if(this->add_bombs)
	{
		this->AddBombs();
	}

	this->add_bombs = !(this->add_bombs);
}

/**
 *
 * \brief Return the string represenation of the bombing_grid.
 *
 * \return The bombing_grid, with O for each bomb, and . for each empty cell.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
string BomberMan::str(void)
{
	int i;
	int j;
	stringstream s;

	for(i = 0; i < this->num_rows; ++i)
	{
		for(j = 0; j < this->num_columns; ++j)
		{
			if(this->bombing_grid[i][j] > 0)
			{
				s << "O";
			}
			else
			{
				s << ".";
			}
		}

		s << "\n";
	}

	return s.str();
}

int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int c;
	int i;
	int n;
	int r;

	cin >> r >> c >> n;

	// The system state repeats itself every 4 steps.
	if(n >= 4)
	{
		n = (n % 4) + 4;
	}

	BomberMan b(r, c);
	b.Initialize();

	for(i = 0; i < n; ++i)
	{
		//cout << b.str() << endl;
		b.Propagate();
	}

	cout << b.str();

	return 0;
}
