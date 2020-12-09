#include <iostream>
#include <string>

using namespace std;

struct BigInt{
	string number;
};

bool intChecker(string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (isdigit(input[i]) == false)
		{
			return false;
		}
	}
	return true;
}

void reverseStr(string& str)
{
	int n = str.length();

	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}

BigInt Add(const BigInt& lhs, const BigInt& rhs)
{
	BigInt c;
	string res = "";
	int len1 = lhs.number.length();
	//cout << len1 << " this in len 1" << endl;
	int len2 = rhs.number.length();
	int carry = 0;

	for (int i = 0; i < len1; i++)
	{
		int sum = ((lhs.number[i] - '0') + (rhs.number[i] - '0') + carry);
		//cout << sum << " this is sum " << endl;
		res.push_back(sum % 10 + '0');

		carry = sum / 10;
	}

	for (int i = len1; i < len2; i++)
	{
		int sum = ((rhs.number[i] - '0') + carry);
		res.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	if (carry)
		res.push_back(carry + '0');

	reverseStr(res);
	c.number = res;
	return c;
}

int main()
{
	BigInt a, b, res;
	int size;

	while (cin >> size)
	{
		string n1, n2;
		bool isInt1, isInt2;
		for (int i = 0; i < size; i++)
		{
			cin >> n1 >> n2;
			isInt1 = intChecker(n1);
			isInt2 = intChecker(n2);
			if (isInt1 == false || isInt2 == false)
			{
				cout << "Not a valid number, please try again." << endl;
				continue;
			}
			else
			{
				if (n1.length() > n2.length())
				{
					string temp = n1;
					n1 = n2;
					n2 = temp;
				}
				reverseStr(n1);
				//cout << "n1 = " << n1 << endl;
				reverseStr(n2);
				//cout << "n2 = " << n2 << endl;
				a.number = n1;
				b.number = n2;
				//cout << a.number << " " << b.number << endl;
				res = Add(a, b);
				cout << res.number << endl;
			}
		}
	}
	return 0;
}

