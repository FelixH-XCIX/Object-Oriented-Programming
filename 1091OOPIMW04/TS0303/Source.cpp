#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	string input;
	string x, c;
	int m = 0;
	int n = 0;
	string word;

	while (getline(cin, input))
	{
		x = x.empty();
		c = c.empty();
		word = word.empty();

		if (input == "\0")
		{
			continue;
		}
		int count = 0;

		stringstream in(input);

		//cout << input << endl;

		while (in >> word)
		{
			if (count == 0)
			{
				x = word;
				//cout << x << " = n" << endl;
			}
			if (count == 1)
			{
				m = stoi(word);
				//cout << m << " = m" << endl;
			}
			if (count == 2)
			{
				n = stoi(word);
				//cout << n << " = n" << endl;
			}
			if (count == 3)
			{
				c = word;
				//cout << c << " = this is c" << endl;
			}
			count++;
		}

		bool dot = false;
		int pos = 0;

		for (int i = 0; i < x.length(); i++)
		{
			if (x[i] == '.')
			{
				dot = true;
				pos = i;
			}
		}

		//for single integer and no other decimal points
		if (!dot && (n == 0))
		{
			int diff = m - x.length();
			string temp = "";

			for (int i = 0; i < diff; i++)
			{
				cout << c;
			}
			cout << x << endl;
			continue;

		}

		//integer digit but there decimal place
		else if (!dot && (n > 0))
		{
			x.push_back('.');

			for (int i = 0; i < n; i++)
			{
				x.push_back('0');
			}
		}

		//it is a double
		else if (dot)
		{

			string decimalNum = x.substr(pos + 1);
			//cout << "decimalNum = " << decimalNum <<  endl;

			if (decimalNum.length() < n)
			{
				int diff = n - decimalNum.length();
				for (int i = 0; i < diff; i++)
				{
					x.push_back('0');
				}
			}
			else if (n == 0)
			{
				x = x.substr(0, pos - 1);
				//cout << "n == 0 -> " << x << " pos = " << pos << endl;
			}
			else if (decimalNum.length() > n)
			{
				x = x.substr(0, pos + 1);
				decimalNum = decimalNum.substr(0, n);
				x = x.append(decimalNum);
			}
		}

		//remainder int 
		if (x.length() < m)
		{
			int diff = m - x.length();
			for (int i = 0; i < diff; i++)
				cout << c;
		}


		cout << x << endl;
	}
	return 0;
}