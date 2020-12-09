//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

#define MAX 100

using namespace std;


int main()
{
	int i, j, numbers[MAX];
	string input;
	while (getline(cin,input))
	{
		int size = input.length();
		for (i = 0; i < size; i++)
		{
			numbers[i] = input[i] - '0';
		}
		for (i = 1; i <= 3; i++)
		{
			for (j = 0; j < size; j++)
			{
				switch (numbers[j])
				{
                case 0:
                    if (i == 1)
                        cout << (" _ ");
                    else if (i == 2)
                        cout << ("| |");
                    else if (i == 3)
                        cout << ("|_|");
                    break;
                case 1:
                    if (i == 1)
                        cout << ("   ");
                    else if (i == 2)
                        cout << ("  |");
                    else if (i == 3)
                        cout << ("  |");
                    break;
                case 2:
                    if (i == 1)
                        cout << (" _ ");
                    else if (i == 2)
                        cout << (" _|");
                    else if (i == 3)
                        cout << ("|_ ");
                    break;
                case 3:
                    if (i == 1)
                        cout << (" _ ");
                    else if (i == 2)
                        cout << (" _|");
                    else if (i == 3)
                        cout << (" _|");
                    break;
                case 4:
                    if (i == 1)
                        cout << ("   ");
                    else if (i == 2)
                        cout << ("|_|");
                    else if (i == 3)
                        cout << ("  |");
                    break;
                case 5:
                    if (i == 1)
                        cout << (" _ ");
                    else if (i == 2)
                        cout << ("|_ ");
                    else if (i == 3)
                        cout << (" _|");
                    break;
                case 6:
                    if (i == 1)
                        cout << (" _ ");
                    else if (i == 2)
                        cout << ("|_ ");
                    else if (i == 3)
                        cout << ("|_|");
                    break;
                case 7:
                    if (i == 1)
                        cout << (" _ ");
                    else if (i == 2)
                        cout << ("  |");
                    else if (i == 3)
                        cout << ("  |");
                    break;
                case 8:
                    if (i == 1)
                        cout << (" _ ");
                    else if (i == 2)
                        cout << ("|_|");
                    else if (i == 3)
                        cout << ("|_|");
                    break;
                case 9:
                    if (i == 1)
                        cout << (" _ ");
                    else if (i == 2)
                        cout << ("|_|");
                    else if (i == 3)
                        cout << (" _|");
                    break;
                }
			}
			cout << endl;
		}
	}
	return 0;
}
