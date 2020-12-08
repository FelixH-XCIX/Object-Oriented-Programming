#include<iostream>
#include<cmath>
#include<vector>

using namespace std;


int main()
{
	int x;
	double temp, avg, sd, var;
	vector<double> member;
	while (cin >> x)
	{
		double input;
		temp = 0;
		for (int i = 0; i < x; i++)
		{
			cin >> input;
			temp += input;
			member.push_back(input);
		}

		avg = temp / x;

		temp = 0;
		for (int j = 0; j < x; j++)
		{
			temp += (member[j] - avg) * (member[j] - avg);
		}

		var = temp / x;
		sd = sqrt(var);

		cout << "Average:" << avg << "\t" << "Standard deviation:" << sd << endl;

		member.clear();
	}

	return 0;
}