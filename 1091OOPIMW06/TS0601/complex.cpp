#include "complex.h"
#include <math.h>
#include <cassert>



Complex::Complex()
{
	this->realValue = 0;
	this->imaginaryValue = 0;
}

Complex::Complex(double realP)
{
	this->realValue = realP;
	this->imaginaryValue = 0;
}

Complex::Complex(double realP, double imagP)
{
	this->realValue = realP;
	this->imaginaryValue = imagP;
}



//getter
double Complex::real()
{
	return realValue;
}
double Complex::imag()
{
	return imaginaryValue;
}



//setter

void Complex::setReal(double r)
{
}
void Complex::setImag(double i)
{
	this->imaginaryValue = i;
}



//global function

double real(Complex a)
{
	return a.real();
}
double imag(Complex a)
{
	return a.imag();
}

double norm(Complex a)
{
	return sqrt(pow(a.real(), 2) + pow(a.imag(), 2));
}



//boolean dunction operator

bool operator==(const Complex a, const Complex b) {
	return(a.realValue == b.realValue && a.imaginaryValue == b.imaginaryValue);
}

bool operator!=(const Complex a, const Complex b) {
	return(a.realValue != b.realValue || a.imaginaryValue != b.imaginaryValue);
}


//input outpur overload

ostream& operator<<(ostream& os_, const Complex& comp_)
{
	return os_ << comp_.realValue << " + " << comp_.imaginaryValue << "*i" << endl;
}


istream& operator>>(istream& is_, Complex& comp_) // assumes a b
{
	double r = 0;
	double i = 0;

	is_ >> r >> i;

	comp_.setReal(r);
	comp_.setImag(i);

	return is_;
}



Complex operator+(double d, Complex b_)
{
	Complex ret(d + b_.real(),  b_.imag());
	return ret;
}

Complex operator-(double d, Complex b_)
{
	Complex ret(d - b_.real(),b_.imag());
	return ret;
}

Complex operator*(double d, Complex b_)
{

	Complex ret(d * b_.realValue, d * b_.imaginaryValue);

	return ret;
}

Complex operator/(double x, Complex b_)
{
	double a = x, b = 0;
	double c = b_.realValue, d = b_.imaginaryValue;
	assert(c || d);

	Complex ret((a * c + b * d) / (c * c + d * d), (b * c - a * d) / (c * c + d * d));

	return ret;
}


Complex Complex::operator+(Complex c)
{
	Complex ret;
	ret.realValue = c.realValue + this->realValue;
	ret.imaginaryValue = c.imaginaryValue + this->imaginaryValue;
	return ret;
}
Complex Complex::operator-(Complex c)
{
	Complex ret;
	ret.realValue = this->realValue - c.realValue;
	ret.imaginaryValue = this->imaginaryValue - c.imaginaryValue;
	return ret;
}
Complex Complex::operator*(Complex o)
{
	double a = realValue, b = imaginaryValue; //x + yi
	double c = o.realValue, d = o.imaginaryValue; //u + vi;
	
	//xu - yv + (xv+yu)*i
	Complex ret(a * c - b * d, b * c + a * d);

	return ret;
}
Complex Complex::operator/(Complex o) 
{
	double a = realValue, b = imaginaryValue;
	double c = o.realValue, d = o.imaginaryValue;
	assert(c || d);

	Complex ret((a * c + b * d) / (c * c + d * d), (b * c - a * d) / (c * c + d * d));

	return ret;
}

double Complex::norm()
{
	double addition = (realValue * realValue) + (imaginaryValue * imaginaryValue);
	double res = sqrt(addition);
	return res;
}