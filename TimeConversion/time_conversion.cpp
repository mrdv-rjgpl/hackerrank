#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int main(int argc, char **argv)
{
	int hour, minute, second;
	char c;
	string time;

	cin >> hour >> c >> minute >> c >> second >> time;

	if(time[0] == 'P' && hour < 12)
	{
		hour += 12;
	}
	else if(time[0] == 'A' && hour == 12)
	{
		hour -= 12;
	}

	cout << setfill('0') << setw(2) << hour << ":";
	cout << setfill('0') << setw(2) << minute << ":";
	cout << setfill('0') << setw(2) << second << endl;

	return 0;
}
