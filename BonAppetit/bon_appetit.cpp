/**
 *
 * \brief Solution to Bon Appetit
 *
 * https://www.hackerrank.com/challenges/bon-appetit
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <bits/stdc++.h>

using namespace std;

/**
 *
 * \brief Determine whether the split was fair for Anna.
 *
 * Print "Bon Appetit" if the split is fair, or the overcharge amount otherwise.
 *
 * \param[in] n The number of courses.
 * \param[in] k The course Anna skipped.
 * \param[in] b The amount Bob charged Anna.
 * \param[in] ar The prices of each item.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
void BonAppetit(int n, int k, int b, vector <int> ar)
{
	int i;
	int sum = 0;

	for(i = 0; i < n; ++i)
	{
		sum += ar[i];
	}

	sum -= ar[k];
	sum /= 2;

	if(sum == b)
	{
		cout << "Bon Appetit" << endl;
	}
	else
	{
		cout << b - sum << endl;
	}
}

int main()
{
	int b;
	int n;
	int k;
	cin >> n >> k;
	vector<int> ar(n);

	for(int ar_i = 0; ar_i < n; ar_i++)
	{
		cin >> ar[ar_i];
	}

	cin >> b;
	BonAppetit(n, k, b, ar);

	return 0;
}
