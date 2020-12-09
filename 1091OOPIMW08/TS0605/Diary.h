#ifndef DIARY_H
#define DIARY_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Diary
{
public:
	// Intent: To act as a default constructor.
	Diary();

	// Function as described on the question paper.
	static void NewDay(string newDay);

	// Intent: To return the currentDate.
	static string currentDay();

	// Intent: To write an entry when a creature's appendix changes.
	void writeEntry(const string creatureName, const string appendix, const int before, const int after, const string entryDate);

	// Intent: To output the current creature's log.
	void outputLog();

private:
	vector <string> diaryContents;			// The contents of a creature's diary (data on the creature's appendixes' changes).
	vector <string> diaryContentDates;	// The dates of each entry in the diary.
	static vector <string> diaryDates;		// The known dates (similar to a calendar).
	static string currentDate;					// The current date.
	static string lastDate;						// The previous date; "yesterday".
	int dateCreated;								// Stores data on when the current creature is created.
};

#endif // !DIARY_H