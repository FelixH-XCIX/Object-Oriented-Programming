#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <vector>
#include<string>
#include "Diary.h"
using namespace std;

class Creature
{
public:
	// Constructors as required on the question paper.
	Creature(string name);
	Creature(string name, const Creature& cloneOf);

	// Array subscript ([]) overload.
	int& operator [](string appendixName);

	// Intent: To print the current creature's status.
	void PrintStatus();

	// Intent: To print the current creature's log.
	void PrintLog();

private:
	string creatureName;							// Current creature's name.
	vector<string> appendixes;				// Current creature's list of appendixes.
															// Unsorted when a new appendix is added. If unsorted, then the list will be sorted before it is printed.
	vector<string> lastDateOfChange;		// Stores each appendix's last date of change.
	vector<int> currentLevel;					// Stores each appendix's current level.
	vector<int>lastLevel;							// Stores each appendix's previous level.
	Diary creatureDiary;							// Creature's diary.
	bool recorded;									// Indicates if an appendix's change is recorded in the diary.
	bool sorted;										// Indicates if an appendix list is sorted.
	int lastChange;									// Stores data on which appendix was last changed.
};

#endif // !CREATURE_H