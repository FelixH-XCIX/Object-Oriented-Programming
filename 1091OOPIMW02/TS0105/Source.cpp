#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.14159265358979323846

using namespace std;

int main()
{
	double radius;
	while (cin >> radius)
	{
		double volume;
		volume = (4  * PI * pow(radius,3)) /3;
		printf("%.6f", volume);
		cout << endl;
	}
}