#pragma once
#include <ctype.h>
#include <iostream>
using namespace std;

class Month
{
public:
	Month();
	Month(char first, char second, char third);
	Month(int monthInt);
	~Month();

	void printList();
	void inputInt();
	void inputStr();
	void outputInt();
	void outputStr();
	int nextMonth();
	int getMonthint();
	void operator=(int n);
	const char monStr[13][4] = {"","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct", "Nov", "Dec" };

private:
	int month;
	
};

