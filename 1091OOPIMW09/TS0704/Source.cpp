#include <string>
#include <iostream>

using namespace std;

int minofThree(int a, int b, int c);

int main()
{
	string s1, s2;

	while (getline(cin, s1))
	{
		getline(cin, s2);
		int matrix[500][500] = { 0 };

		int lens1 = s1.size();
		int lens2 = s2.size();

		for (int i = 0; i < lens1; i++) matrix[i][0] = i;
		for (int i = 0; i < lens2; i++) matrix[0][i] = i;

		for (int y = 1; y < lens2; y++)
			for (int x = 1; x < lens1; x++)
			{
				int sub = (s1[x - 1] == s2[y - 1]) ? (0) : (1);
				matrix[x][y] = minofThree(matrix[x][y - 1] + 1, matrix[x - 1][y - 1] + sub, matrix[x - 1][y] + 1);
			}


		cout << matrix[lens1][lens2] << endl;
	}
}

int minofThree(int a, int b, int c)
{
	int min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	return min;
}