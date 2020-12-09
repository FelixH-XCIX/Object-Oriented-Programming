#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int maxValue(vector<int>& x)
{
	int max = 0;
	for (int i = 0; i < x.size(); i++)
	{
		max = (x[i] > max) ? x[i] : max;
	}

	return max;
}
int main()
{
	string input;
	while (getline(cin, input))
	{
		string key;
		getline(cin, key);
		vector<int>keyv;

		stringstream ss;
		ss << key;
		int temp;
		while (ss >> temp)
		{
			keyv.push_back(temp);
		}

		int row = maxValue(keyv) + 1;
		int col = (input.size() % row) ? input.size() / row : (input.size() / row) + 1;
		//cout << row << " " << col << endl;

		//make 2d pointer array
		char** table = new char* [row];
		for (int i = 0; i < row; ++i) {
			table[i] = new char[col];
		}

		int pointi = 0;
		for (int i = 0; i <= col; i++)
		{
			//cout << "masuk loop col " << endl;
			for (int j = 0; j < row; j++)
			{
				//cout << pointi << " ";
				//cout << "masuk loop rwo " << endl;
				if (pointi != input.size())
				{

					table[j][i] = (input[pointi] == ' ') ? '_' : input[pointi];
					//cout << j << " " << i << " " << table[j][i] << endl;
					pointi++;
				}
				else
				{
					table[j][i] = '\0';
				}
			}
			//cout << endl;
		}

		/*for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << table[i][j];
			}
			cout << endl;
		}*/

		string res;
		for (int i = 0; i < keyv.size(); i++)
		{
			int crow = keyv[i];
			for (int j = 0; j <= col; j++)
			{
				if (table[crow][j] == '\0')
					continue;
				else
					res += table[crow][j];
			}
		}

		cout << res << endl;

		/*for (int i = 0; i < row; i++) {
			delete[] table[i];
		}
		delete[] table;*/

		ss.clear();
		keyv.clear();
	}
}