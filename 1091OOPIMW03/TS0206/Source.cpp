#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double payment;
	while (cin >> payment)
	{
		if (payment < 750)
			cout << fixed << setprecision(2) << 0.01 * payment << endl;
		else if (payment >= 750 && payment < 2250)
			cout << fixed << setprecision(2) << 7.50 + (0.02 * (payment - 750)) << endl;
		else if (payment >= 2250 && payment < 3750)
			cout << fixed << setprecision(2) << 37.50 + (0.03 * (payment - 2250)) << endl;
		else if (payment >= 3750 && payment < 5250)
			cout << fixed << setprecision(2) << 82.50 + (0.04 * (payment - 3750)) << endl;
		else if (payment >= 5250 && payment < 7000)
			cout << fixed << setprecision(2) << 142.50 + (0.05 * (payment - 5250)) << endl;
		else if (payment > 7000)
			cout << fixed << setprecision(2) <<  230 + (0.06 * (payment - 7000)) << endl;
	}

	return 0;
}