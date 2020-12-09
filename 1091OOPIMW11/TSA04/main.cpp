#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

void printVector(vector<char> x)
{
	for (int i = 0; i < x.size(); i++)
	{
		if(x[i] != NULL)
			cout << x[i];
	}
	cout << endl;
}

void printArr(int arr[][7])
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
}
int main()
{
	int x;
	int blockA[7][7], blockB[7][7];
	while (cin >> x)
	{
		vector<char>result;

		for (int k = 0; k < x; k++)
		{
			string input;
			if(k == 0)
				cin.ignore();
			for (int i = 0; i < 7; i++)
			{

				getline(cin, input);
				for (int j = 0; j < 7; j++)
				{
					int temp = input[j] - '0';
					//cout << j << " " << input[j] << " " << temp << endl;
					switch (temp)
					{
					case 0:
						blockA[i][j] = 0;
						blockB[i][j] = 0;
						break;
					case 1:
						blockA[i][j] = 0;
						blockB[i][j] = 1;
						break;
					case 2:
						blockA[i][j] = 1;
						blockB[i][j] = 0;
						break;
					case 3:
						blockA[i][j] = 1;
						blockB[i][j] = 1;
						break;
					}
				}
				cin.clear();
			}

			/*cout << endl;
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					cout << blockA[i][j];
				}
				cout << endl;
			}

			cout << endl;

			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					cout << blockB[i][j];
				}
				cout << endl;
			}

			cout << endl;*/

			for (int i = 6; i >= 0; i--)
			{
				int powx = 0;
				int res = 0;
				for (int j = 6; j >= 0; j--)
				{
					res += pow(2, powx) * blockA[i][j];
					//cout << res << " " << blockA[i][j] << endl;
					powx++;
				}
				result.push_back(res);
			}

			for (int i = 0; i < 7; i++)
			{
				int powx = 0;
				int res = 0;
				for (int j = 6; j >= 0; j--)
				{
					res += pow(2, powx) * blockB[j][i];
					//cout << res << " " << blockB[j][i] << endl;
					powx++;
				}
				result.push_back(res);
			}


		}
		printVector(result);
		result.clear();
	}
}