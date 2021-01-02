#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	string input;
	string word[100];
	int listcount = 0;
	string command;
	string name[100];
	int score[100];
	while (getline(cin, input))
	{
		int count = 0;
		stringstream ss(input);
		while (ss >> word[count])
		{
			count++;
		}
		if (word[0] == "insert")
		{
			int doublename = 0;
			if (listcount > 0)
			{

				for (int i = 0; i < listcount; i++)
				{
					if (word[1] == name[i])
					{
						cout << "insert fail with " << name[i] << "!!!" << endl;
						doublename = 1;
						break;
					}
				}


			}
			if (doublename == 0)
			{
				name[listcount] = word[1];
				int number = stoi(word[2]);
				score[listcount] = (number);
				listcount++;
				cout << "insert success with name " << word[1] << endl;
			}
		}
		else if (word[0] == "search")
		{
			int alphabet = 0;
			if (isalpha(word[1][0]))alphabet = 1;
			if (alphabet == 1)
			{
				int found = 0;
				for (int i = 0; i < listcount; i++)
				{
					if (word[1] == name[i])
					{
						cout << word[1] << " score is " << score[i] << endl;
						found = 1;
						break;
					}
				}
				if (found == 1)
				{
				}
				else if (found == 0)
				{
					cout << word[1] << " is not in system!!!" << endl;
				}
			}
			else if (alphabet == 0)
			{
				int number = stoi(word[1]);
				int found = 0;
				for (int i = 0; i < listcount; i++)
				{
					if (score[i] > number)
					{
						found = 1;
						cout << name[i] << endl;
					}
				}
				if (found == 0)
				{
					cout << "no one match the condition" << endl;
				}
			}
		}
		else if (word[0] == "update")
		{
			int found = 0;
			for (int i = 0; i < listcount; i++)
			{
				if (word[1] == name[i])
				{
					found = 1;
					int alphabet = 0;
					if (isalpha(word[2][0]))alphabet = 1;
					if (alphabet == 0)
					{
						int number = stoi(word[2]);
						score[i] = number;
						cout << "update value success" << endl;
					}
					else if (alphabet == 1)
					{
						name[i] = word[2];
						cout << "update name success" << endl;
					}
					break;
				}
			}
			if (found == 0)
			{
				cout << word[1] << " is not in system!!!" << endl;
			}
		}
		else if (word[0] == "delete")
		{
			int found = 0;
			for (int i = 0; i < listcount; i++)
			{
				if (word[1] == name[i])
				{
					found = 1;
					//delete name[i]
					name[i].erase();
					for (int j = i; j < listcount - 1; j++)
					{
						score[j] = score[j + 1];
						name[j] = name[j + 1];
					}
					listcount--;
					//delete score[i]

					cout << "remove " << word[1] << endl;
					break;
				}

			}
			if (found == 0)
			{
				cout << word[1] << " is not in system!!!" << endl;
			}
		}
		else if (word[0] == "score")
		{
			int found = 0;
			for (int i = 0; i < listcount; i++)
			{
				if (word[1] == name[i])
				{
					found = 1;
					if (score[i] < 60 && score[i]>0)
					{
						cout << "grade: F" << endl;
					}
					else if (score[i] >= 60 && score[i] < 70)
					{
						cout << "grade: C" << endl;
					}
					else if (score[i] >= 70 && score[i] < 80)
					{
						cout << "grade: B" << endl;
					}
					else if (score[i] >= 80 && score[i] < 90)
					{
						cout << "grade: A" << endl;
					}
					else if (score[i] >= 90 && score[i] <= 100)
					{
						cout << "grade: A+" << endl;
					}
					break;
				}

			}
			if (found == 0)
			{
				cout << word[1] << " is not in system!!!" << endl;
			}
		}
		else if (word[0] == "show")
		{
			for (int i = 0; i < listcount; i++)
			{
				cout << name[i] << ", " << score[i] << endl;
			}
		}
		else
		{

		}
	}
}