#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#define MAX 10

using namespace std;

//struct as instruction
typedef struct
{
	char firstName[25];
	char lastName[30];
	char phone[15];
} StRec;



int main()
{
	StRec student[MAX];
	string input;
	int dataCounter = 0;

	//temporary array of char for string processing
	char firstNameC[25];
	char lastNameC[30];
	char phoneC[15];

	//bool 
	bool errorS, errorD, errorI, found, same;
	int dataCount = 0;

	while (cin >> input)
	{
		//cout << dataCount << endl;
		int type;
		//determine the type of order
		if (input == "insert")
			type = 1;
		else if (input == "delete")
			type = 2;
		else if (input == "print")
			type = 3;
		else if (input == "search")
			type = 4;
		else
			type = 5;

		switch (type)
		{
			//insert
		case 1:
			//cout << "enter insertion " << endl;
			errorI = false;
			same = false;
			cin >> firstNameC >> lastNameC >> phoneC;

			//data fullness checker;
			if (dataCount > 9)
			{
				cout << "Insert Error" << endl;
				errorI = true;
				break;
			}

			//char length checker
			if (strlen(firstNameC) > 25 || strlen(lastNameC) > 30 || strlen(phoneC) > 15)
			{
				cout << "Input Error" << endl;
				errorI = true;
				break;
			}

			//digit phone number checker
			for (int i = 0; i < strlen(phoneC); i++)
			{
				if (!isdigit(phoneC[i]))
				{
					cout << "Input Error" << endl;
					errorI = true;
					break;
				}
			}

			for (int i = 0; i < dataCount; i++)
			{
				if (strcmp(student[i].firstName, firstNameC) == 0 && strcmp(student[i].lastName, lastNameC) == 0 && strcmp(student[i].phone, phoneC) == 0)
				{
					cout << "Insert Error" << endl;
					same = true;
					break;
				}
			}

			if (!same && !errorI)
			{
				strcpy(student[dataCount].firstName, firstNameC);
				strcpy(student[dataCount].lastName, lastNameC);
				strcpy(student[dataCount].phone, phoneC);

				dataCount++;
			}

			break;


			//deletion
		case 2:
			//cout << "enter deletion" << endl;
			int pointer;
			found = false;
			errorD = false;
			cin >> firstNameC >> lastNameC >> phoneC;
			//char length checker
			if (strlen(firstNameC) > 25 || strlen(lastNameC) > 30 || strlen(phoneC) > 15)
			{
				cout << "Input Error" << endl;
				errorD = true;
				break;
			}

			//digit phone number checker
			for (int i = 0; i < strlen(phoneC); i++)
			{
				if (!isdigit(phoneC[i]))
				{
					cout << "Input Error" << endl;
					errorD = true;
					break;
				}
			}

			for (int i = 0; i < dataCount; i++)
			{
				if (strcmp(student[i].firstName, firstNameC) == 0 && strcmp(student[i].lastName, lastNameC) == 0 && strcmp(student[i].phone, phoneC) == 0)
				{
					pointer = i;
					found = true;
					break;
				}
			}

			if (!found)
			{
				cout << "Delete Error" << endl;
			}
			else if (found)
			{
				for (int i = pointer; i < dataCount - 1; i++)
				{
					strcpy(student[i].firstName, student[i + 1].firstName);
					strcpy(student[i].lastName, student[i + 1].lastName);
					strcpy(student[i].phone, student[i + 1].phone);
				}
				dataCount--;
			}

			break;


			//print
		case 3:
			//cout << "enter Print" << endl;
			if (dataCount == 0)
			{
				cout << "Print Error" << endl;
			}
			else
			{
				for (int i = 0; i < dataCount; i++)
				{
					cout << student[i].firstName << " " << student[i].lastName << " " << student[i].phone << endl;
				}
			}

			break;

			//search
		case 4:
			//cout << "enter search" << endl;
			found = false;
			errorS = false;
			//int pointer = 0;
			cin >> firstNameC >> lastNameC >> phoneC;
			//data fullness checker;
			if (dataCount == 0)
			{
				cout << "Search Error" << endl;
				errorS = true;
				break;
			}

			//char length checker
			if (strlen(firstNameC) > 25 || strlen(lastNameC) > 30 || strlen(phoneC) > 15)
			{
				cout << "Input Error" << endl;
				errorS = true;
				break;
			}

			//digit phone number checker
			for (int i = 0; i < strlen(phoneC); i++)
			{
				if (!isdigit(phoneC[i]))
				{
					cout << "Input Error" << endl;
					errorS = false;
					break;
				}
			}

			for (int i = 0; i < dataCount; i++)
			{
				if (strcmp(student[i].firstName, firstNameC) == 0 && strcmp(student[i].lastName, lastNameC) == 0 && strcmp(student[i].phone, phoneC) == 0)
				{
					cout << i << endl;
					found = true;
					break;
				}
			}

			if (!found)
				cout << "Search Error" << endl;

			break;

			//input user not detected
		case5:
			cout << "Input Error" << endl;
			break;
		}

	}
}
	