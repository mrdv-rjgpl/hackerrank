/**
 *
 * \file equal.cpp
 *
 * \brief Solution to https://www.hackerrank.com/challenges/equal/problem
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>

using namespace std;

int EqualizeChocolates(void);
int ReduceNumChocolates(int num_colleagues, int num_chocolates[], int num_choc_final);

/**
 *
 * \brief Determine the minimum number of operations to equalize the number of chocolates across colleagues.
 *
 * \details The permissible operations are:
 * \li Giving 1 chocolate to all but one colleague
 * \li Giving 2 chocolates to all but one colleague
 * \li Giving 5 chocolates to all but one colleague
 * Equivalently, these can be written as:
 * \li Taking 1 chocolate from one colleague
 * \li Taking 2 chocolates from one colleague
 * \li Taking 5 chocolates from one colleague
 *
 * Keeping this in mind, we first obtain the minimum number \f$ m \f$ of chocolates available with a single colleague.
 * Since the available reductions are in steps of 5, 2, and 1, we see that the final number of chocolates available
 * with each colleague can be \f$ m \f$, \f$ m - 1 \f$, \f$ m - 2 \f$, \f$ m - 3 \f$, or \f$ m - 4 \f$. Targeting a
 * final number \f$ m - i \f$ of chocolates, for \f$ i >= 5 \f$ will be less optimal, because the sequence of operations
 * \f$ S_i \f$ to get to \f$ m - i \f$ chocolates can be reduced to the sequence \f$ S_{i mod 5} \f$, followed by
 * a sequence of reduce-by-5 operations for each colleague.
 *
 * \retval num_operations The number of operations required to equalize the number of chocolates.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int EqualizeChocolates(void)
{
	int i;
	int n;
	int min_num_chocolates_index = 0;
	int min_num_operations_index = 0;
	int num_operations[5];

	cin >> n;
	int num_chocolates[n];

	/* Obtain the number of chocolates available with each colleague and the index of the colleague with the fewest. */
	for(i = 0; i < n; ++i)
	{
		cin >> num_chocolates[i];

		if(num_chocolates[i] < num_chocolates[min_num_chocolates_index])
		{
			min_num_chocolates_index = i;
		}
		else
		{
			/* No operation */
		}
	}

	/* Reduce each colleague to the established fewest number of chocolates with a single colleague. */
	for(i = 0; i < 5; ++i)
	{
		num_operations[i] = ReduceNumChocolates(n, num_chocolates, num_chocolates[min_num_chocolates_index] - i);

		if(num_operations[min_num_operations_index] > num_operations[i])
		{
			min_num_operations_index = i;
		}
		else
		{
			/* No operation */
		}
	}

	return num_operations[min_num_operations_index];
}

/**
 *
 * \brief Get the number of operations required to reduce each colleague's chocolate to the provided target number.
 *
 * \param[in] num_colleagues The number of colleagues
 * \param[in] num_chocolates The number of chocolates originally available with each colleague
 * \param[in] num_choc_final The target number of chocolates to reduce each colleague's stash to
 *
 * \retval num_operations The number of operations required to perform the reductions
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int ReduceNumChocolates(int num_colleagues, int num_chocolates[], int num_choc_final)
{
	int i;
	int num_operations = 0;
	int current_num_chocolates;

	for(i = 0; i < num_colleagues; ++i)
	{
		/* Obtain the number of chocolates the colleague starts with. */
		current_num_chocolates = num_chocolates[i];

		/* Reduce that number to the target number of chocolates. */
		while(current_num_chocolates > num_choc_final)
		{
			if(current_num_chocolates - num_choc_final >= 5)
			{
				/* If a reduction by 5 is possible, reduce by 5. */
				current_num_chocolates -= 5;
			}
			else if(current_num_chocolates - num_choc_final >= 2)
			{
				/* If a reduction by 2 is possible, reduce by 2. */
				current_num_chocolates -= 2;
			}
			else
			{
				/* Go with the only option left, and reduce by 1. */
				--current_num_chocolates;
			}

			++num_operations;
		}
	}

	return num_operations;
}

int main(int argc, char **argv)
{
	int i;
	int t;

	cin >> t;

	for(i = 0; i < t; ++i)
	{
		cout << EqualizeChocolates() << endl;
	}

	return 0;
}
