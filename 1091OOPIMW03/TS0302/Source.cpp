#include<iostream>
#include<vector>
#include <string>
#include <sstream>
#include<fstream>

using namespace std;

int main()
{
	string input;
	vector<int>g1;
	ifstream infile;
	ofstream outfile;

	infile.open("grade.txt");

	getline(infile, input);

	
	outfile.open("grades.Output");
	int freq[1000] = { 0 };

	stringstream in(input);

	while (1) 
	{
		int n;
		in >> n;
		if (!in)
			break;
		g1.push_back(n);
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < g1.size(); j++)
		{
			if (i == g1[j])
			{
				freq[i]++;
			}
		}
	}

	for (int i = 0; i < 6; i++)
	{
		outfile << freq[i] << " grade(s) of " << i << endl;
	}

	infile.close();
	outfile.close();
	g1.clear();


	return 0;
}