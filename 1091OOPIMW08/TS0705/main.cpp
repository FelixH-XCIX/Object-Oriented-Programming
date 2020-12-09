#include <iostream>
#include <string>
using namespace std;


void operation_A(const string number1, string* number2);

void operation_R(string* number2);

void operation_L(string* number2);

int main()
{
	int T;
	while (cin >> T)
	{
		int counter = 1;

		string output[12];
		output[0] = "COWCULATIONS OUTPUT\n";

		while (T > 0)
		{
			T--;
			string Num1, Num2, realOutput;
			cin >> Num1 >> Num2;

			char operation;
			for (int i = 0; i < 3; i++)
			{
				cin >> operation;

				if (operation == 'A')
				{
					operation_A(Num1, &Num2);
				}
				else if (operation == 'R')
				{
					operation_R(&Num2);
				}
				else if (operation == 'L')
				{
					operation_L(&Num2);
				}
			}

			cin >> realOutput;

			if (realOutput == Num2)
			{
				output[counter] = "YES\n";
				// cout << "YES\n";
			}
			else
			{
				output[counter] = "NO\n";
				// cout << "NO\n";
			}

			counter++;
		}

		output[counter] = "END OF OUTPUT\n";
		counter++;

		for (int i = 0; i < counter; i++)
		{
			cout << output[i];
		}


	}

	return 0;
}

void operation_A(const string number1, string* number2)
{
	int temp1[8] = { 0 }, temp2[8] = { 0 }, temp3[8] = { 0 };
	int carry = 0;

	for (int i = 4; i > -1; i--)
	{
		if (number1[i] == 'V') temp1[i + 3] = 0;
		else if (number1[i] == 'U') temp1[i + 3] = 1;
		else if (number1[i] == 'C') temp1[i + 3] = 2;
		else if (number1[i] == 'D') temp1[i + 3] = 3;
	}

	int j = (*number2).size() - 1;
	for (int i = 7; i > -1; i--)
	{
		if (j < 0)
		{
			temp2[i] = 0;
		}
		else
		{
			if ((*number2)[j] == 'V') temp2[i] = 0;
			else if ((*number2)[j] == 'U') temp2[i] = 1;
			else if ((*number2)[j] == 'C') temp2[i] = 2;
			else if ((*number2)[j] == 'D') temp2[i] = 3;
		}
		j--;

	}


	for (int i = 7; i > -1; i--)
	{
		temp3[i] = temp1[i] + temp2[i] + carry;

		if (temp3[i] > 3)
		{
			carry = temp3[i] / 4;
			temp3[i] %= 4;
		}
		else
		{
			carry = 0;
		}
	}


	*number2 = "VVVVVVVV";

	for (int i = 0; i < 8; i++)
	{
		if (temp3[i] == 0) (*number2)[i] = 'V';
		else if (temp3[i] == 1) (*number2)[i] = 'U';
		else if (temp3[i] == 2) (*number2)[i] = 'C';
		else if (temp3[i] == 3) (*number2)[i] = 'D';
	}

	// cout << *number2 << endl;
}

void operation_R(string* number2)
{
	while ((*number2).size() < 8)
	{
		(*number2) = "V" + (*number2);
	}

	string res = "VVVVVVVV";

	for (int i = 1; i < 8; i++)
	{
		res[i] = (*number2)[i - 1];
	}

	(*number2) = res;

}

void operation_L(string* number2)
{
	while ((*number2).size() < 8)
	{
		(*number2) = "V" + (*number2);
	}

	string res = "VVVVVVVV";

	for (int i = 6; i > -1; i--)
	{
		res[i] = (*number2)[(*number2).size() - 7 + i];
	}

	(*number2) = res;

}