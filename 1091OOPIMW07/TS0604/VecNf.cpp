#include "VecNf.h"


bool dimSame(int x, int y)
{
	if (x == y)
		return true;
	else
		return false;
}

VecNf::VecNf()
{
	//member = new float [1];
	member.push_back(0);
	dim = 1;
}

VecNf::VecNf(vector<float> x, int cnt)
{
	//member = new float[cnt];
	for (int i = 0; i < cnt; i++)
	{
		member.push_back(x[i]);
	}
	dim = cnt;

}

VecNf::VecNf(const VecNf& rhs)
{
	//member = new float[rhs.dim];
	int size = rhs.dim;
	member.clear();
	for (int i = 0; i < size; i++)
	{
		member.push_back(rhs.member[i]);
	}
	dim = size;
}

VecNf::VecNf(float dest[], int cnt)
{
	//member = new float[cnt];
	for (int i = 0; i < cnt; i++)
	{
		member.push_back(dest[i]);
	}
	dim = cnt;
	
}

VecNf::VecNf(float x, int d)
{
	//member = new float[1];
	member.push_back(x); 
	dim = d;
}

VecNf VecNf::operator*(VecNf& x)
{
	bool check = dimSame(x.dim, dim);
	float temp = 0;
	if (check)
	{
		for (int i = 0; i < x.dim; i++)
		{
			temp += member[i] * x.member[i];
		}
		VecNf res(temp, 1);
		return res;
	}
	else
	{
		VecNf res;
		cout << "dimensions inconsistent" << endl;
		return res;
	}
}

void VecNf::operator*(float x)
{
	for (int i = 0; i < dim; i++)
	{
		member[i] *= x;
	}
}

void VecNf::operator= (const VecNf& D)
{
	//member = new float[D.dim];
	member.clear();
	int size = D.dim;
	cout << "ASSIGNMENT!!!" << endl;
	for (int i = 0; i < size; i++)
	{
		member.push_back(D.member[i]);
	}	
	dim = size;	
}

int VecNf::Size()
{
	return dim;
}

float& VecNf::operator[](int i)
{
	if (i > dim)
	{
		cout << "Index out of bounds" << endl;
	}
	else
		return member[i];
}

ostream& operator <<(ostream& output, const VecNf& x)
{
	for (int i = 0; i < x.dim; i++)
	{
		output << x.member[i];
	}

	return output;
}

VecNf VecNf::operator+(VecNf& x)
{
	int size = x.dim;
	bool check = dimSame(x.dim, this->dim);
	//float* res;
	//res = new float[x.dim]; 
	vector<float> xt;
	if (check)
	{
		for (int i = 0; i < x.dim; i++)
		{
			xt.push_back(x.member[i] + member[i]);
		}
		
		VecNf resx(xt, size);
		return resx;
		//delete[] res;
	}
	else
	{
		VecNf resx;
		cout << "dimensions inconsistent" << endl;
		return resx;
	}
}

VecNf VecNf::operator-(VecNf& x)
{
	int size = x.dim;
	bool check = dimSame(x.dim, dim);
	//float* res;
	//res = new float[x.dim]; 
	vector<float> xt;
	if (check)
	{
		for (int i = 0; i < x.dim; i++)
		{
			xt.push_back(x.member[i] - member[i]);
		}

		VecNf resx(xt, size);
		return resx;
		//delete[] res;
	}
	else
	{
		VecNf resx;
		cout << "dimensions inconsistent" << endl;
		return resx;
	}
}