#include <iostream>
#include <string>
#include <fstream>
#include <utility>

using namespace std;

void HighScore(string arr[], int score[], int x)
{
	int topIndex[4];
	int topValue[4] = { 0 };

	for (int i = 0; i < x; i++)
	{
		topIndex[2] = i;
		topValue[2] = score[i];

		if (topValue[2] > topValue[1])
		{
			swap(topValue[2], topValue[1]);
			swap(topIndex[2], topIndex[1]);

			if (topValue[1] > topValue[0])
			{
				swap(topValue[1], topValue[0]);
				swap(topIndex[1], topIndex[0]);
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		cout << arr[topIndex[i]] << endl << score[topIndex[i]] << endl;
	}
}

int main()
{
	ifstream inStream;

	inStream.open("scores.txt");
	string input[100];
	int x = 0, score[100] = { 0 };
	while (inStream >> input[x] >> score[x])
	{
		x++;
	}

	HighScore(input, score, x);

}