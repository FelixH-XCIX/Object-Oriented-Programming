#include "Month.h"



Month::Month()
{
	month = 1;
}

Month::Month(char first, char second, char third)
{
	bool valid = false;
	char str[5];
	str[0] = first;
	str[1] = second;
	str[2] = third;

	//check to the array char to find the correct value of int
	for (int i = 1; i <= 12; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (monStr[i][j] != str[j])
			{
				break;
				valid = false;
			}
			if (j == 2)
			{
				month = i;
				valid = true;
			}
		}
	}

	if (!valid)
		month = 1;
}

Month::Month(int n)
{
	if (n >= 1 && n <= 12)
		month = (n % 12 == 0) ? 12 : n % 12;
	else
		month = 1;
}


Month::~Month()
{
}

void Month::inputInt()
{
	int n;
	cin >> n;
	if (n >= 1 && n <= 12)
		month = (n % 12 == 0) ? 12 : n % 12;
	else
		month = 1;
}

void Month::printList()
{
	for (int i = 1; i < 13; i++)
	{
		cout << i << " ";
		for (int j = 0; j < 3; j++)
		{
			cout << monStr[i][j] << " ";
		}
		cout << endl;
	}
}
void 
Month::inputStr()
{
	bool valid = false;
	char str[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> str[i];
	}
	//check to the array char to find the correct value of int
	for (int i = 1; i <= 12; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (monStr[i][j] != str[j])
			{
				break;
				valid = false;
			}
			if (j == 2)
			{
				month = i;
				valid = true;
			}
		}
	}

	if (!valid)
		month = 1;
}

void Month::outputInt()
{
	cout << month;
}


int Month::getMonthint()
{
	return month;
}
void Month::outputStr()
{
	for (int i = 0; i < 3; i++)
	{
		int temp = getMonthint();
		cout <<  monStr[temp][i];
	}
}

int Month::nextMonth()
{
	int n;
	n = month + 1;
	return n;
}

void Month::operator=(int n)
{
	month = (n % 12 == 0) ? 12 : n % 12;
}