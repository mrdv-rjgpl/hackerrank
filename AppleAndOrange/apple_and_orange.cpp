#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 *
 * \brief Get number of fruits falling in range of house.
 *
 * Compute the absolute position of each fruit. If it lies within the bounds [house_range_lower, house_range_upper], then increment the fruit count.
 *
 * \param[in] house_range_lower The lower bound of the house.
 * \param[in] house_range_upper The upper bound of the house.
 * \param[in] tree_position The absolute position of the tree from which the fruits fall.
 * \param[in] fruits The positions of fallen fruits relative to the tree.
 *
 * \return fruit_count The number of fruits fallen within the house.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int GetFruitCount(int house_range_lower, int house_range_upper, int tree_position, vector<int> fruits)
{
	int fruit_count = 0;
	int absolute_fruit_position;
	ssize_t i;

	for(i = 0; i < fruits.size(); ++i)
	{
		absolute_fruit_position = fruits[i] + tree_position;

		if(house_range_lower <= absolute_fruit_position
			&& absolute_fruit_position <= house_range_upper)
		{
			++fruit_count;
		}
	}

	return fruit_count;
}

int main()
{
	int s;
	int t;
	int a;
	int b;
	int m;
	int n;

	cin >> s >> t;
	cin >> a >> b;
	cin >> m >> n;

	vector<int> apple(m);
	vector<int> orange(n);

	for(int apple_i = 0;apple_i < m;apple_i++)
	{
		cin >> apple[apple_i];
	}

	for(int orange_i = 0;orange_i < n;orange_i++)
	{
		cin >> orange[orange_i];
	}

	cout << GetFruitCount(s, t, a, apple) << endl;
	cout << GetFruitCount(s, t, b, orange) << endl;

	return 0;
}
