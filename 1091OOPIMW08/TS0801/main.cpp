#include "Polynomial.h"
#include <iostream>  

using namespace std;

int main()
{
	Polynomial empty;
	double one[] = { 1 };
	Polynomial One(one, 1);
	double quad[] = { 3, 2, 1 };
	double cubic[4] = { 1, 2, 0, 3 };
	Polynomial q(quad, 3); // q is 3 + 2*x + x*x
	Polynomial c(cubic, 4);// c is 1 + 2*x + 0*x*x + 3*x*x*x
	Polynomial p = q;  // test copy constructor
	Polynomial r;
	r = q;             //test operator=
	r = c;

	//cout << "Polynomial q " << endl;
	//for (int i = 0; i < 3; i++)
	//	cout << "term with degree " << i << " has coefficient " << q[i] << endl;

	//cout << "Polynomial c " << endl;
	//for (int i = 0; i < 4; i++)
	//	cout << "term with degree " << i << " has coefficient " << c[i] << endl;
	
	cout << endl << r[9] << endl;

	cout << "Polynomial r " << endl;
	for (int i = 0; i < 10; i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;

	cout << "value of q(2) is " << evaluate(q, 2) << endl;
	cout << "value of p(2) is " << evaluate(p, 2) << endl;
	cout << "value of r(2) is " << evaluate(r, 2) << endl;
	cout << "value of c(2) is " << evaluate(c, 2) << endl;

	/*r = 3 + q;
	cout << "value of (q + c)(0) is " << evaluate(r, 0) << endl;
	*/
	cout << endl;
	r = 77 - c;
	cout << evaluate(c -77 , -2);
	for (int i = 0; i < 4; i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;

	cout << endl;

	r = c - 50;
	for (int i = 0; i < 4; i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;

	cout << endl;

	r = q * c;
	cout << "size of q*c is " << r.mySize() << endl;
	cout << "Polynomial r (= q*c) " << endl;

	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;

	cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;

	return 0;
}