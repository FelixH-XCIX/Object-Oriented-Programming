#pragma once
#include <iostream>  

using namespace std;

class Polynomial
{
public:
	Polynomial() :coef(nullptr), size(0) {} // creates an empty polynomial
	Polynomial(const Polynomial& poly);
	Polynomial(double coefficient[], int size);
	Polynomial(double x);
	~Polynomial();

	//overloading [] operator
	double& operator[](int degree)
	{
		if (degree >= size)
		{
			cout << "Index Out Of Range!" << endl;
			return coef[1];
		}
		else
		{
			//cout << "size of polynomial is = " << size << endl;
			return this->coef[degree];
		}
	}

	//This is required if we are to have const correctness
	const double& operator[](int degree)const
	{
		if (degree >= size)
		{
			cout << "Index Out Of Range!" << endl;
			return coef[1];
		}
		else
		{
			//cout << "size of polynomial is = " << size << endl;
			return this->coef[degree];
		}
	}

	const Polynomial& operator=(const Polynomial& rhs);
	int mySize() { return size; }

	//friend functions:
	friend double evaluate(const Polynomial& poly, double arg);
	friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
	friend Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs);
	friend Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs);

private:
	double* coef;
	int size;

};
