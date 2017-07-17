#include <bits/stdc++.h>

using namespace std;

/**
 *
 * \brief Get the number of times records are broken.
 *
 * \param[in] a The list of scores.
 *
 * \return record_break_count The count of record breaks.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
vector<int> getRecord(vector<int> a)
{
	vector<int> record(2);
	vector<int> record_break_count(2);

	ssize_t i;

	for(i = 0; i < record.size(); ++i)
	{
		record[i] = a[0];
		record_break_count[i] = 0;
	}

	for(i = 0; i < a.size(); ++i)
	{
		if(a[i] > record[0])
		{
			record[0] = a[i];
			++record_break_count[0];
		}
		else if(a[i] < record[1])
		{
			record[1] = a[i];
			++record_break_count[1];
		}
	}

	return record_break_count;
}

int main()
{
	int n;

	cin >> n;
	vector<int> s(n);

	for(int s_i = 0; s_i < n; s_i++)
	{
		cin >> s[s_i];
	}

	vector<int> result = getRecord(s);
	string separator = "", delimiter = " ";

	for(auto val: result)
	{
		cout << separator << val;
		separator = delimiter;
	}

	cout << endl;

	return 0;
}

