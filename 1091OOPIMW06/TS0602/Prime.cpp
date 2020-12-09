//Name: B10615006	
//Date: 4/10/2018
//Last Update: 4/11/2018
//Problem statement: Prime Number

#include "PrimeNumber.h"

bool IsPrime(int number)
{

	if (number == 2 || number == 3)
		return true;

	if (number % 2 == 0 || number % 3 == 0)
		return false;

	int divisor = 6;
	while (divisor * divisor - 2 * divisor + 1 <= number)
	{

		if (number % (divisor - 1) == 0)
			return false;

		if (number % (divisor + 1) == 0)
			return false;

		divisor += 6;

	}

	return true;

}

int nextPrime(int a)
{

	while (!IsPrime(++a))
	{
	}
	return a;

}

int prevPrime(int a)
{

	while (!IsPrime(--a))
	{
	}
	return a;

}


//constructor
PrimeNumber::PrimeNumber()
{
	this->value = 1;
}

PrimeNumber::PrimeNumber(int number)
{
	this->value = number;
}

//getter value
int PrimeNumber::get()
{
	return this->value;
}

//postfix ++ and -- operator overload

// Intent: increase to the next big prime number  
// Pre   : if called
// Post  : returned the old value, while increment the object that is called
PrimeNumber PrimeNumber::operator++(int)
{
	int x = this->value;
	PrimeNumber old(x);

	this->value = nextPrime(x);

	return old;
}

// Intent: increase to the next small prime number  
// Pre	 :  if called
// Post  : returned the old value, while increment the object that is called
PrimeNumber PrimeNumber::operator--(int)
{
	int x = this->value;
	PrimeNumber old(x);

	this->value = prevPrime(x);
	return old;
}


//prefix ++ and -- operator overload

// Intent: increase to the next bigger prime number  
// Pre	 : if called
// Post  : the object that called being changed and returned the object with the new value
PrimeNumber& PrimeNumber::operator++()
{
	int x = this->value;

	this->value = nextPrime(x);
	PrimeNumber newPrime(this->value);
	

	return newPrime;
}

// Intent: increase to the next smaller prime number  
// Pre	 : if called
// Post  :  the object that called being changed and returned the object with the new value
PrimeNumber& PrimeNumber::operator--()
{
	int n = this->value;


	this->value = prevPrime(n);
	
	PrimeNumber newPrime(this->value);

	return newPrime;
}

//assign operator overload

PrimeNumber& PrimeNumber::operator=(PrimeNumber a)
{
	this->value = a.value;
	return *this;
}

PrimeNumber& PrimeNumber::operator=(int a)
{
	this->value = a;
	return *this;
}