#include <iostream>

using namespace std;

int main()
{
	unsigned long long int n;
	while (cin >> n)
	{
		unsigned long long int hour, minute, second, remT;
		remT = n % 60;
		minute = n / 60;
		second = remT;

		
		hour = minute / 60;
		minute -= hour * 60;

		cout << hour << " hours " << minute << " minutes and " << second << " seconds" << endl;
	}

	return 0;
}