/**
 *
 * \brief Solution to challenge Day of the Programmer
 *
 * https://www.hackerrank.com/challenges/day-of-the-programmer
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <bits/stdc++.h>

using namespace std;

/**
 *
 * \brief Find the day of the programmer for the given year.
 *
 * \param[in] year The year to compute the day of the programmer in.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
string DayOfTheProgrammer(int year)
{
	stringstream s;

	if(year <= 1917)
	{
		/* Julian calendar - all multiple-of-4 years are leap years. */
		if(year % 4 == 0)
		{
			s << "12.09." << year;
		}
		else
		{
			s << "13.09." << year;
		}
	}
	else if(year == 1918)
	{
		/* Transition year - 31st day of the year was Jan 31, 32nd day of the year was Feb 14th. */
		s << "26.09." << year;
	}
	else
	{
		/* Gregorian calendar - standard rules. */
		if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		{
			s << "12.09." << year;
		}
		else
		{
			s << "13.09." << year;
		}
	}

	return s.str();
}

int main()
{
	int year;

	cin >> year;
	cout << DayOfTheProgrammer(year) << endl;

	return 0;
}
