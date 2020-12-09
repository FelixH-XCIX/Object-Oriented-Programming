#include <iostream>
#include <algorithm>  

using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}


int main()
{
	int a;
	while (cin >> a)
	{
		int b;
		cin >> b;
        //cout << a << " " << b << endl;
        unsigned int result = gcd(a, b);
        cout << result << endl;
	}
}