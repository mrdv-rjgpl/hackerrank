#include <bits/stdc++.h>

using namespace std;

/**
 *
 * \brief Return the maximum non divisible subset of the vector.
 *
 * \param[in] n The size of the input vector.
 * \param[in] k The divisor for the sums of pairs.
 * \param[in] input The input vector.
 *
 * \return max_non_div_subset_size The maximum size of the non divisible subset.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int NonDivisibleSubsetSize(int n, int k, vector<int> input)
{
	int max_non_div_subset_size = 0;
	int i;
	vector<int> remainder_counts(k);

	for(i = 0; i < n; ++i)
	{
		++remainder_counts[input[i] % k];
	}

	for(i = 1; 2 * i < k; ++i)
	{
		if(remainder_counts[i] > remainder_counts[k - i])
		{
			max_non_div_subset_size += remainder_counts[i];
		}
		else
		{
			max_non_div_subset_size += remainder_counts[k - i];
		}
	}

	/* At most one multiple of 'k' can be added to the set. */
	if(remainder_counts[0] > 0)
	{
		++max_non_div_subset_size;
	}

	/* If 'k' is even, then at most one number of the form (n + 0.5) * k can be added to the set. */
	if(k % 2 == 0 && remainder_counts[k / 2] > 0)
	{
		++max_non_div_subset_size;
	}

	/* If the set is empty, then one number can be taken to form a non-divisible subset. */
	if(max_non_div_subset_size == 0)
	{
		max_non_div_subset_size = 1;
	}

	return max_non_div_subset_size;
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

	cout << NonDivisibleSubsetSize(n, k, ar) << endl;

	return 0;
}

