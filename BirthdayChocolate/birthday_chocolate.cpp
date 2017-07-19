#include <bits/stdc++.h>

using namespace std;

/**
 *
 * \brief Compute the cumulative sum of the given vector.
 *
 * \param[in] input the vector of integers to sum.
 *
 * \return cumulative_sum The cumulative sum.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
vector<int> GetCumulativeSum(vector<int> input)
{
	ssize_t i;
	vector<int> cumulative_sum(input.size());

	cumulative_sum[0] = input[0];
	//cout << "[" << cumulative_sum[0] << ", ";

	for(i = 1; i < input.size(); ++i)
	{
		cumulative_sum[i] = cumulative_sum[i - 1] + input[i];
		//cout << cumulative_sum[i] << ", ";
	}

	//cout << "]" << endl;

	return cumulative_sum;
}

/**
 *
 * \brief Get number of segments of input whose sum equals the given number.
 *
 * \param[in] input The vector to be segmented and summed.
 * \param[in] m The size of contiguous segments.
 * \param[in] d The required sum value.
 *
 * \return num_sum_segments The number of segments whose sum matches d.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int GetNumSumSegments(vector<int> input, int d, int m)
{
	int num_sum_segments = 0;
	int i;

	vector<int> cumulative_sum = GetCumulativeSum(input);

	/* Check for the (m - 1)th element in the cumulative sum as that is the sum of the first m values. */
	if(cumulative_sum[m - 1] == d)
	{
		++num_sum_segments;
	}

	for(i = m; i < cumulative_sum.size(); ++i)
	{
		if(cumulative_sum[i] - cumulative_sum[i - m] == d)
		{
			++num_sum_segments;
		}
	}

	return num_sum_segments;
}

int main()
{
	int n;
	int d;
	int m;

	cin >> n;

	vector<int> s(n);

	for(int s_i = 0; s_i < n; s_i++)
	{
		cin >> s[s_i];
	}

	cin >> d >> m;
	cout << GetNumSumSegments(s, d, m) << endl;

	return 0;
}

