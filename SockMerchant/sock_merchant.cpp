/**
 *
 * \brief Sock merchant challenge.
 *
 * https://www.hackerrank.com/challenges/sock-merchant
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 */
#include <bits/stdc++.h>

#define MAX_NUM_SOCK_COLOURS 101

using namespace std;

/**
 *
 * \brief Sort the socks according to colour, and then count the number of pairs.
 *
 * \param[in] n The number of socks to be sorted.
 * \param[in] ar The colour of each sock.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int SockMerchant(int n, vector <int> ar)
{
	int i;
	int sock_colours[MAX_NUM_SOCK_COLOURS] = {0};
	int num_pairs = 0;

	for(i = 0; i < n; ++i)
	{
		++sock_colours[ar[i]];
	}

	for(i = 0; i < MAX_NUM_SOCK_COLOURS; ++i)
	{
		num_pairs += sock_colours[i] / 2;
	}

	return num_pairs;
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

	cout << SockMerchant(n, ar) << endl;

	return 0;
}

