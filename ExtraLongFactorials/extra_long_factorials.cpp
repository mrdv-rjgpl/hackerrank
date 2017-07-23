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

		LargeInteger operator+=(int n);
		LargeInteger operator*=(int n);
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

LargeInteger LargeInteger::operator+=(int n)
{
	int i;
	int carry = n;
	int sum = 0;

	for(i = 0; i < this->n.size(); ++i)
	{
		sum = this->n[i] + carry;
		carry = sum / 10;
		this->n[i] = sum % 10;
	}

	while(carry > 0)
	{
		this->n.push_back(carry % 10);
		carry /= 10;
	}

	return *this;
}

LargeInteger LargeInteger::operator*=(int n)
{
	int i;
	int carry = 0;
	int product;

	for(i = 0; i < this->n.size(); ++i)
	{
		product = (this->n[i] * n) + carry;
		this->n[i] = product % 10;
		carry = product / 10;
	}

	while(carry > 0)
	{
		this->n.push_back(carry % 10);
		carry /= 10;
	}

	return *this;
}

int main()
{
	int i;
	int n;

	cin >> n;

	LargeInteger l(1);

	for(i = 1; i <= n; ++i)
	{
		l *= i;
	}

	cout << l.str() << endl;

	return 0;
}
