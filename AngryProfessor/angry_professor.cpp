#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 *
 * \brief Determine if the class was cancelled.
 *
 * Use the minimum number of students required and student arrival times.
 *
 * \param[in] n The number of students in class.
 * \param[in] k The minimum number of students required to be present on time.
 * \param[in] arrival_times The individual arrival times of each student, relative to the class start time.
 *
 * \return true If the class is cancelled.
 * \return false If the class is held.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
bool DetermineClassCancellation(int n, int k, vector<int> arrival_times)
{
	bool class_cancelled = true;
	int i;
	int num_students_on_time = 0;

	for(i = 0; i < n; ++i)
	{
		if(arrival_times[i] <= 0)
		{
			++num_students_on_time;

			if(num_students_on_time >= k)
			{
				class_cancelled = false;

				break;
			}
		}
	}

	return class_cancelled;
}

int main()
{
	int t;

	cin >> t;

	for(int a0 = 0; a0 < t; a0++)
	{
		int n;
		int k;

		cin >> n >> k;

		vector<int> a(n);

		for(int a_i = 0;a_i < n;a_i++)
		{
			cin >> a[a_i];
		}

		if(DetermineClassCancellation(n, k, a))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}

