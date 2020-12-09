#include "Diary.h"

string Diary::currentDate = "no date";
string Diary::lastDate = "no date";
vector <string> Diary::diaryDates(0);

Diary::Diary()
{
	lastDate = currentDate;
	dateCreated = diaryDates.size() - 1;
}

void Diary::NewDay(string newDay)
{
	lastDate = currentDate;
	currentDate = newDay;
	diaryDates.push_back(newDay);
}

string Diary::currentDay()
{
	return currentDate;
}

void Diary::writeEntry(const string creatureName, const string appendix, const int before, const int after, const string entryDate)
{
	string newEntry;

	diaryContentDates.push_back(entryDate);
	newEntry = creatureName + "'s " + appendix;

	if (before == 0 && after > 0)
	{
		newEntry += " appeared (";
	}
	else if (before > 0 && after == 0)
	{
		newEntry += " disappeared (";
	}
	else if (before > after)
	{
		newEntry += " decreased (";
	}
	else
	{
		newEntry += " increased (";
	}

	newEntry += to_string(before) + " -> " + to_string(after);
	newEntry += ").\n";

	diaryContents.push_back(newEntry);
}

void Diary::outputLog()
{
	int writtenEntry = 0;

	for (int i = 0; i < diaryDates.size(); i++)
	{
		if (i < dateCreated) 
			continue;
		cout << "Day " << diaryDates[i] << endl;
		if (writtenEntry >= diaryContentDates.size()) 
			break;
		while (diaryContentDates[writtenEntry] == diaryDates[i])
		{
			cout << diaryContents[writtenEntry];
			writtenEntry++;
			if (writtenEntry >= diaryContentDates.size()) break;
		}

	}
}
