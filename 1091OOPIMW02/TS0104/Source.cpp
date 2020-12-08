#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	while (cin >> input)
	{
		if ((int)input.length() < 10)
		{
			int remainder = 10 - input.length();
			for (int i = 0; i < remainder; i++)
			{
				cout << " ";
			}

			cout << input << endl;
		}
		else
			cout << input << endl;
	}
}