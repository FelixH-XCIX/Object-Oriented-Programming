#include <iostream>


using namespace std;

class PrimeNumber {
public:
	int value;
	int get();
	int PrimeList;
	PrimeNumber();
	PrimeNumber(int _value);
	PrimeNumber& operator++();
	PrimeNumber operator++(int);
	PrimeNumber& operator--();
	PrimeNumber operator--(int);
	PrimeNumber& operator=(PrimeNumber a);
	PrimeNumber& operator=(int a);
};