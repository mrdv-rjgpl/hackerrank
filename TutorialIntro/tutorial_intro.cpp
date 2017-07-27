/**
 *
 * \brief Solution to tutorial intro challenge.
 *
 * https://www.hackerrank.com/challenges/tutorial-intro
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 *
 * \brief Find the index of the given number in the given sorted vector.
 *
 * \param[in] input The sorted vector of numbers.
 * \param[in] element The number to search for.
 *
 * \return i the index of the element in the vector.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int FindIndex(vector<int> input, int element)
{
	int i = 1;
	int index_increment;

	while(i < input.size())
	{
		i <<= 1;
	}

	index_increment = i / 2;
	--i;

	while(index_increment > 0)
	{
		if(i > input.size() || input[i] > element)
		{
			i -= index_increment;
		}
		else if(input[i] < element)
		{
			i += index_increment;
		}
		else
		{
			break;
		}

		index_increment /= 2;
	}

	return i;
}

int main()
{
	int i;
	int b;
	int n;

	cin >> b >> n;

	vector<int> a(n);

	for(i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	cout << FindIndex(a, b) << endl;

	return 0;
}
