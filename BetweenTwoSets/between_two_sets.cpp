#include <bits/stdc++.h>

using namespace std;

/**
 *
 * \brief Get the HCF of the given numbers.
 *
 * \param[in] a The first number.
 * \param[in] b The second number.
 *
 * \retval The HCF of a and b.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int GetHighestCommonFactor(int a, int b)
{
	int min = (a > b)? b: a;
	int max = a + b - min;

	while(1)
	{
		if(max % min == 0)
		{
			return min;
		}
		else
		{
			int temp = min;

			min = max % min;
			max = temp;
		}
	}
}

/**
 *
 * \brief Get the HCF of the given vector
 *
 * \param[in] a The set of integers to compute the HCF of.
 *
 * \return a_hcf The HCF of a.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int GetHighestCommonFactor(vector<int> a)
{
	int a_hcf = a[0];
	int i;

	for(i = 1; i < a.size(); ++i)
	{
		a_hcf = GetHighestCommonFactor(a_hcf, a[i]);
	}

	return a_hcf;
}

/**
 *
 * \brief Get the LCM of the given numbers.
 *
 * \param[in] a The first number.
 * \param[in] b The second number.
 *
 * \retval The LCM of a and b.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int GetLowestCommonMultiple(int a, int b)
{
	return (a * b) / GetHighestCommonFactor(a, b);
}

/**
 *
 * \brief Get the LCM of the given vector
 *
 * \param[in] a The set of integers to compute the LCM of.
 *
 * \return a_lcm The LCM of a.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int GetLowestCommonMultiple(vector<int> a)
{
	int a_lcm = a[0];
	int i;

	for(i = 1; i < a.size(); ++i)
	{
		a_lcm = GetLowestCommonMultiple(a_lcm, a[i]);
	}

	return a_lcm;
}

int GetTotalX(vector<int> a, vector<int> b)
{
	// Complete this function
	int a_lcm = GetLowestCommonMultiple(a);
	int b_hcf = GetHighestCommonFactor(b);
	int i = 1;
	int x = 0;

	while(1)
	{
		if(b_hcf % (a_lcm * i) == 0)
		{
			++x;
		}
		else if(a_lcm * i > b_hcf)
		{
			break;
		}

		++i;
	}

	return x;
}

int main()
{
	int i;
	int m;
	int n;

	cin >> n >> m;

	vector<int> a(n);
	vector<int> b(m);

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for(int i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	cout << GetTotalX(a, b) << endl;

	return 0;
}

