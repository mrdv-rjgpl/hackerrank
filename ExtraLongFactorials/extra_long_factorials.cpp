#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

class LargeInteger
{
	private:
		vector<int> n;

	public:
		LargeInteger(int n);
		string str();
};

LargeInteger::LargeInteger(int n)
{
	while(n > 0)
	{
		this->n.push_back(n % 10);

		n /= 10;
	}
}

string LargeInteger::str()
{
	int i;
	stringstream s;

	for(i = this->n.size() - 1; i >= 0; --i)
	{
		s << this->n[i];
	}

	return s.str();
}

int main()
{
	int n;

	cin >> n;

	LargeInteger l(n);

	cout << l.str() << endl;

	return 0;
}
