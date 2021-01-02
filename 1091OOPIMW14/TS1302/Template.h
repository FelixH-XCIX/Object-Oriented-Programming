#pragma once
#include <iostream>

using namespace std;

// Intent: to find the absolute value o between two values
// Pre	 : two variables
// Post	 : the difference
template<class T>
double absoluteValue(T a, T b)
{
	return (a > b) ? a - b : b - a;
}