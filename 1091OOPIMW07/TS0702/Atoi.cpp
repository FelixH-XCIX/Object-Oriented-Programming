#include "Atoi.h"


//Constructor
Atoi::Atoi()
{
}
Atoi::Atoi(string s)
{
	beTrans = s;
}


// Intent:	setter for string element
// Pre   :	string s
// Post  :	beTrans element changed
void Atoi::SetString(string s)
{
	beTrans = s;
}

// Intent:	getter for the element string beTrans
// Pre	 :	if called
// Post  :	return string beTrans
const string Atoi::GetString()
{
	return this->beTrans;
}

// Intent:	getter for the length of string
// Pre	 :	if called
// Post  :	return length
int Atoi::Length()
{
	int n = 0;
	while (beTrans[n] != NULL)
	{
		n++;
	}
	if (beTrans[0] == '-')
	{
		return n - 1;
	}
	else
	{
		return n;
	}
}

// Intent:	check wether or not is all number
// Pre	 :	if called
// Post  :	return true or false
bool Atoi::IsDigital()
{
	if (beTrans[0] == '-')
	{
		for (int i = 1; i < this->Length(); i++)
		{
			if (this->beTrans[i] < 48 || this->beTrans[i] > 57)
			{
				return false;
			}
		}
	}
	else
	{
		for (int i = 0; i < this->Length(); i++)
		{
			if (this->beTrans[i] < 48 || this->beTrans[i] > 57)
			{
				return false;
			}
		}
	}
	return true;
}

// Intent:	to get the integer value
// Pre	 :	if called
// Post  :	return int
int Atoi::StringToInteger()
{
	int res = 0;
	if (beTrans[0] == '-')
	{
		res -= beTrans[1] - '0';
		for (int i = 2; i < beTrans.length(); i++)
		{
			res = res * 10;
			res -= (int)beTrans[i] - '0';
		}
	}
	else
	{
		res += beTrans[0] - '0';
		for (int i = 1; i < beTrans.length(); i++)
		{
			res = res * 10;
			res += (int)beTrans[i] - '0';
		}
	}
	return res;
}