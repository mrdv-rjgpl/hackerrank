/**
 *
 * \brief Solution to picking numbers challenge.
 *
 * https://www.hackerrank.com/challenges/picking-numbers
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define MAX_VALUE 100

using namespace std;

/**
 *
 * \brief Compute the required set size.
 *
 * The set must be chosen such that the difference between any two numbers is <= 1.
 *
 * \param[in] input The input numbers.
 *
 * \return max_set_size The largest possible set size.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int PickingNumbers(vector<int> input)
{
	int i;
	int max_set_size = 0;
	vector<int> input_hist(MAX_VALUE);
	vector<int> input_hist_cumulative_sum(MAX_VALUE);

	for(i = 0; i < input.size(); ++i)
	{
		++input_hist[input[i]];
	}

	input_hist_cumulative_sum[0] = input_hist[0];

	for(i = 1; i < input_hist.size(); ++i)
	{
		input_hist_cumulative_sum[i] = input_hist_cumulative_sum[i - 1] + input_hist[i];
	}

	max_set_size = input_hist_cumulative_sum[1];

	for(i = 2; i < input_hist_cumulative_sum.size(); ++i)
	{
		if(input_hist_cumulative_sum[i] - input_hist_cumulative_sum[i - 2] > max_set_size)
		{
			max_set_size = input_hist_cumulative_sum[i] - input_hist_cumulative_sum[i - 2];
		}
	}

	return max_set_size;
}

int main()
{
	int n;

	cin >> n;

	vector<int> a(n);

	for(int a_i = 0;a_i < n;a_i++)
	{
		cin >> a[a_i];
	}

	cout << PickingNumbers(a) << endl;

	return 0;
}

