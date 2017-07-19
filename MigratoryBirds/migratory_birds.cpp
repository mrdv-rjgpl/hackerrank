#include <bits/stdc++.h>

using namespace std;

/**
 *
 * \brief Get index of most populous migratory bird.
 *
 * \details Since the number of types of birds is just five, and the possible counts can go up to 10^5,
 * it is more advantageous to first find the count, and then find the index of the max count from amongst them.
 *
 * \param[in] input The bird counts.
 *
 * \return bird_index The most populous bird's type index.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int GetMigratoryBirdCounts(vector<int> input)
{
	int i;
	int bird_index = 0;
	vector<int> bird_counts(6); /* So that we don't have to bother with counting from 1 and 0 issues. */

	for(i = 0; i < input.size(); ++i)
	{
		++bird_counts[input[i]];
	}

	for(i = 0; i < bird_counts.size(); ++i)
	{
		if(bird_counts[i] > bird_counts[bird_index])
		{
			bird_index = i;
		}
	}

	return bird_index;
}

int main()
{
	int n;

	cin >> n;

	vector<int> ar(n);

	for(int ar_i = 0; ar_i < n; ar_i++)
	{
		cin >> ar[ar_i];
	}

	cout << GetMigratoryBirdCounts(ar) << endl;

	return 0;
}

