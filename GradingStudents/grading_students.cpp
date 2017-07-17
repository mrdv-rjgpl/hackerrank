#include <bits/stdc++.h>

using namespace std;

/**
 *
 * \brief Round grades according to Sam's rules.
 *
 * If a student's grade is < 40, the student fails.
 * If the grade is < the next multiple of 5 by less than 3, then it's rounded up.
 * If the grade is less than 38, it's not rounded up.
 *
 * \author Mardava Gubbi <mardava.gubbi@teamindus.in>
 *
 */
vector<int> RoundGrades(vector<int> grades)
{
	ssize_t i;
	vector<int> rounded_grades(grades.size());

	for(i = 0; i < grades.size(); ++i)
	{
		if((grades[i] < 38) || (grades[i] % 5 < 3))
		{
			rounded_grades[i] = grades[i];
		}
		else
		{
			rounded_grades[i] = grades[i] + 5 - (grades[i] % 5);
		}
	}

	return rounded_grades;
}

int main()
{
	int n;
	cin >> n;
	vector<int> grades(n);

	for(int grades_i = 0; grades_i < n; grades_i++)
	{
		cin >> grades[grades_i];
	}

	vector <int> result = RoundGrades(grades);

	for(ssize_t i = 0; i < result.size(); i++)
	{
		cout << result[i] << (i != result.size() - 1 ? "\n" : "");
	}

	cout << endl;

	return 0;
}
