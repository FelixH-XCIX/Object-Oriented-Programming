#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int matrix[7][7] = { 0 };

	string input;
	while (cin >> input)
	{
		if (input.length() < 14)
		{
			int diff = 14 - input.length();
			for (int i = 0; i < diff; i++)
			{
				input += '\0';
			}
		}
		if (input.length() > 14)
		{
			int count = 0;
			string container[100] = { "" };
			int containercount = 0;
			while (count != input.length())
			{
				for (int i = 0; i < 14; i++)
				{
					if (count == input.length())
					{
						int diff = 14 - (input.length() % 14);
						for (int j = 0; j < diff; j++)
						{
							container[containercount] += '\0';
						}
						break;
					}
					container[containercount] += input[count];
					count++;
				}
				containercount++;
			}

			for (int a = 0; a < containercount; a++)
			{
				string A_set;
				string B_set;
				A_set.clear();
				B_set.clear();

				for (int i = 0; i < 7; i++)
				{
					A_set.push_back(container[a][i]);
				}
				for (int i = 7; i < 14; i++)
				{
					B_set.push_back(container[a][i]);
				}

				int A_table[7][7] = { 0 };
				int B_table[7][7] = { 0 };
				int indexA = 0;
				int indexB = 0;
				//buat A table
				for (int i = A_set.length() - 1; i >= 0; i--)
				{
					vector<int>a;
					int n = (int)A_set[i];
					//change integer to binary code
					while (n > 0)
					{
						a.push_back(n % 2);
						n = n / 2;
					}
					if (a.size() < 7)
					{
						int diff = 7 - a.size();
						for (int i = 0; i < diff; i++)
						{
							a.push_back(0);
						}
					}
					reverse(a.begin(), a.end());
					/*for (int i = 0; i < a.size(); i++)
					{
						cout << a[i];
					}
					cout << endl;*/
					for (int i = 0; i < 7; i++)
					{
						A_table[indexA][i] = a[i];
					}
					indexA++;

				}

				for (int i = 0; i < B_set.length(); i++)
				{
					vector<int>b;
					int n = (int)B_set[i];
					//change integer to binary code
					while (n > 0)
					{
						b.push_back(n % 2);
						n = n / 2;
					}
					if (b.size() < 7)
					{
						int diff = 7 - b.size();
						for (int i = 0; i < diff; i++)
						{
							b.push_back(0);
						}
					}
					reverse(b.begin(), b.end());

					for (int i = 0; i < 7; i++)
					{
						B_table[indexB][i] = b[i];
					}
					indexB++;

				}
				//B table res yg udah jadi
				int B_tableRes[7][7] = { 0 };
				for (int i = 0; i < 7; i++)
				{
					for (int j = 0; j < 7; j++)
					{
						B_tableRes[i][j] = B_table[j][i];
					}
				}

				//addition A*2+B
				for (int i = 0; i < 7; i++)
				{
					for (int j = 0; j < 7; j++)
					{
						A_table[i][j] *= 2;
					}
				}

				for (int i = 0; i < 7; i++)
				{
					for (int j = 0; j < 7; j++)
					{
						matrix[i][j] = A_table[i][j] + B_tableRes[i][j];
					}
				}
				//print matrix result
				for (int i = 0; i < 7; i++)
				{
					for (int j = 0; j < 7; j++)
					{
						cout << matrix[i][j];
					}
					cout << endl;
				}
			}
			continue;
		}
		string A_set = "";
		string B_set = "";
		for (int i = 0; i < 7; i++)
		{
			A_set += input[i];
		}
		for (int i = 7; i < input.length(); i++)
		{
			B_set += input[i];
		}
		//cout << A_set << endl;
		//cout << B_set << endl;
		int A_table[7][7] = { 0 };
		int B_table[7][7] = { 0 };
		int indexA = 0;
		int indexB = 0;
		//buat A table
		for (int i = A_set.length() - 1; i >= 0; i--)
		{
			vector<int>a;
			int n = (int)A_set[i];
			//change integer to binary code
			while (n > 0)
			{
				a.push_back(n % 2);
				n = n / 2;
			}
			if (a.size() < 7)
			{
				int diff = 7 - a.size();
				for (int i = 0; i < diff; i++)
				{
					a.push_back(0);
				}
			}
			reverse(a.begin(), a.end());

			for (int i = 0; i < 7; i++)
			{
				A_table[indexA][i] = a[i];
			}
			indexA++;

		}
		
		for (int i = 0; i < B_set.length(); i++)
		{
			vector<int>b;
			int n = (int)B_set[i];

			while (n > 0)
			{
				b.push_back(n % 2);
				n = n / 2;
			}
			if (b.size() < 7)
			{
				int diff = 7 - b.size();
				for (int i = 0; i < diff; i++)
				{
					b.push_back(0);
				}
			}
			reverse(b.begin(), b.end());

			for (int i = 0; i < 7; i++)
			{
				B_table[indexB][i] = b[i];
			}
			indexB++;

		}
		//B table res yg udah jadi
		int B_tableRes[7][7] = { 0 };
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				B_tableRes[i][j] = B_table[j][i];
			}
		}

		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				A_table[i][j] *= 2;
			}
		}
		//hasil akhirnya
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				matrix[i][j] = A_table[i][j] + B_tableRes[i][j];
			}
		}
		//print matrix result
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				cout << matrix[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
