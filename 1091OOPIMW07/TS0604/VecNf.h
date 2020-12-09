#pragma once
#include <iostream>
#include <vector>

using namespace std;

class VecNf {
public:
	VecNf();
	VecNf(const VecNf& rhs);
	VecNf(float [], int cnt);
	VecNf(float x, int d);
	VecNf(vector<float> x, int d);
	VecNf operator*(VecNf& x);
	VecNf operator+(VecNf& x);
	VecNf operator-(VecNf& x);
	void operator*(float x);
	void operator= (const VecNf& D);
	int Size();
	float& operator[](int i);
	friend ostream& operator <<(ostream& output, const VecNf& x);
	
	int dim;
	vector<float>member;
};