/**
 *
 * \brief Solution to save the prisoner challenge
 *
 * https://www.hackerrank.com/challenges/save-the-prisoner
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <bits/stdc++.h>

using namespace std;

/**
 *
 * \brief Compute the index of the prisoner at risk of poisoning.
 *
 * \param[in] n The number of prisoners.
 * \param[in] m The number of sweets.
 * \param[in] s The index of the first prisoner in the circle to be given a sweet.
 *
 * \details The first (m - (m % n)) sweets will be distributed without a hassle. Assuming the sweet
 * distribution starts at the first prisoner, the ((m - 1) % n)^th prisoner counting from zero, or the
 * (((m - 1) % n) + 1)^th prisoner counting from 1, will receive the last sweet and risk being poisoned. 's' is
 * the offset index provided to us, counting from 1. In a circle, this is equivalent to adding (s - 1) sweets to the
 * beginning of the queue (not the end, as the poisoned sweet remains at the end). Hence, the final index of the
 * prisoner at risk of being poisoned is ((((m - 1) + (s - 1)) % n) + 1).
 *
 * \return The index of the prisoner at risk of being poisoned.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int SaveThePrisoner(int n, int m, int s)
{
	return (((m + s - 2) % n) + 1);
}

int main()
{
	int t;

	cin >> t;

	for(int a0 = 0; a0 < t; a0++)
	{
		int n;
		int m;
		int s;
		cin >> n >> m >> s;
		cout << SaveThePrisoner(n, m, s) << endl;
	}

	return 0;
}

