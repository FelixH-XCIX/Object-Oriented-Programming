#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int freq = 0;
	long int input;
	long int storage[1000][2];

	for (int i = 0; i < 1000; i++)
		storage[i][1] = 0;


	while (cin >> input)
	{
		bool same = false;
		for (int i = 0; i <=freq; i++)
		{
			if (storage[i][0] == input)
			{
				storage[i][1]++;
				same = true;
				break;
			}
			else
			{
				same = false;
			}
		}

		if (same == false) 
		{
			//cout << "input value at " << freq << endl;
			if (freq == 0 && input == 0)
				break;
			else
			{
				storage[freq][0] = input;
				storage[freq][1]++;
				freq++;
			}
		}
	}

	for (int i = 0; i < freq - 1; i++)
	{
		for (int j = 0; j < freq - i - 1; j++)
		{
			if (storage[j][0] > storage[j + 1][0])
			{
				int temp = storage[j][0];
				storage[j][0] = storage[j + 1][0];
				storage[j + 1][0] = temp;

				int temps = storage[j][1];
				storage[j][1] = storage[j + 1][1];
				storage[j + 1][1] = temps;
			}
		}
	}

	//cout << "freq before print " << freq << endl;
	cout << "N" << "\t" << "count" << endl;
	for (int i = freq - 1; i >= 0; i--)
	{
		cout << storage[i][0] << "\t" << storage[i][1] << endl;
	}

	return 0;
}
