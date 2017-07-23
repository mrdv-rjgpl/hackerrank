#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 *
 * \brief Large integer manipulation class.
 *
 * The class stores the large integer in the base-10 form, with the least significant digit at the
 * lowest index of the vector.
 *
 * Multiply and add regular integers to a large integer with this class.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
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

/**
 *
 * \brief Construct a LargeInteger object with the value of the input integer.
 *
 * \param[in] n The input integer.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
LargeInteger::LargeInteger(int n)
{
	while(n > 0)
	{
		this->n.push_back(n % 10);

		n /= 10;
	}
}

/**
 *
 * \brief Return the string value of the object.
 *
 * \return The string value of the integer.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
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

/**
 *
 * \brief Overload the += operator with an integer variable on the RHS.
 *
 * \param[in] n The input integer.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
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

/**
 *
 * \brief Overload the *= operator with an integer variable on the RHS.
 *
 * \param[in] n The input integer.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
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
