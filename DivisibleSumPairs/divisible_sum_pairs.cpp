#include <bits/stdc++.h>

using namespace std;

/**
 *
 * \brief Return the number of divisible sum pairs in the vector.
 *
 * Store the counts of remainder values in a vector.
 * Take the corresponding counts of 'i' and 'k - i' and multiply them together.
 * Subtract the repeats in the case of 'i = 0'.
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
	int num_div_sum_pairs;
	int i;
	vector<int> remainder_counts(k);

	for(i = 0; i < n; ++i)
	{
		++remainder_counts[input[i] % k];
	}

	num_div_sum_pairs = (remainder_counts[0] * (remainder_counts[0] - 1)) / 2;

	for(i = 1; 2 * i < k; ++i)
	{
		num_div_sum_pairs += (remainder_counts[i] * remainder_counts[k - i]);
	}

	if(k % 2 == 0)
	{
		num_div_sum_pairs += (remainder_counts[k / 2] * (remainder_counts[k / 2] - 1)) / 2;
	}

	return num_div_sum_pairs;
}

/**
 *
 * \brief Return the number of divisible sum pairs in the vector.
 *
 * Use the brute force method - summing each pair and dividing by 'k'.
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
int DivisibleSumPairsBruteForce(int n, int k, vector<int> input)
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

