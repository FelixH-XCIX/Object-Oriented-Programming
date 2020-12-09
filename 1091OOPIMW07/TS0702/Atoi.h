
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Atoi
{

private:
	string beTrans;
	char sign;
public:
	//constructor
	Atoi();
	Atoi(string s);

	//functions
	void SetString(string s);
	const string GetString();
	int Length();
	bool IsDigital();
	int StringToInteger();

};

