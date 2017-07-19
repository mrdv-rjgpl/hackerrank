#include <bits/stdc++.h>

using namespace std;

/**
 *
 * \brief Return the number of divisible sum pairs in the vector.
 *
 * \param[in] n The size of the input vector.
 * \param[in] k The divisor of the sum of potential pairs.
 * \param[in] input The input vector.
 *
 * \return num_div_sum_pairs The number of divisible sum pairs.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int DivisibleSumPairs(int n, int k, vector<int> input)
{
	int num_div_sum_pairs = 0;
	int i;
	int j;

	for(i = 0; i < n; ++i)
	{
		for(j = i + 1; j < n; ++j)
		{
			if((input[i] + input[j]) % k == 0)
			{
				++num_div_sum_pairs;
			}
		}
	}

	return num_div_sum_pairs;
}

int main()
{
	int n;
	int k;

	cin >> n >> k;

	vector<int> ar(n);

	for(int ar_i = 0; ar_i < n; ar_i++)
	{
		cin >> ar[ar_i];
	}

	cout << DivisibleSumPairs(n, k, ar) << endl;

	return 0;
}

