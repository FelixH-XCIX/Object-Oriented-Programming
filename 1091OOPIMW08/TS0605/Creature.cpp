#include "Creature.h"

Creature::Creature(string name)
{
	creatureName = name;
	recorded = true;
}

Creature::Creature(string name, const Creature& cloneOf)
{
	creatureName = name;
	for (int i = 0; i < cloneOf.appendixes.size(); i++)
	{
		appendixes.push_back(cloneOf.appendixes[i]);
		currentLevel.push_back(cloneOf.currentLevel[i]);
		lastLevel.push_back(cloneOf.currentLevel[i]);
		lastDateOfChange.push_back("no date");
	}

	sorted = false;
	recorded = true;
}

int& Creature::operator[] (string appendixName)
{
	// Checks if an unrecorded change exists.
	if (!recorded && lastLevel[lastChange] != currentLevel[lastChange])
	{
		// Records unrecorded change.
		creatureDiary.writeEntry(creatureName, appendixes[lastChange], lastLevel[lastChange], currentLevel[lastChange], lastDateOfChange[lastChange]);
		recorded = true;
		sorted = false;
	}

	int i;
	for (i = 0; i < appendixes.size(); i++)
	{
		if (appendixes[i] == appendixName) 
			break;
	}

	if (i == appendixes.size())
	{
		// Adds a new appendix.
		appendixes.push_back(appendixName);
		lastLevel.push_back(0);
		currentLevel.push_back(0);
		lastDateOfChange.push_back(Diary::currentDay());

		sorted = false;
	}
	else
	{
		// Edits an existing appendix.
		lastLevel[i] = currentLevel[i];
		lastDateOfChange.at(i) = Diary::currentDay();
	}

	lastChange = i;
	recorded = false;
	return currentLevel[i];
}

void Creature::PrintStatus()
{
	// Checks if an unrecorded change exists.
	if (!recorded && lastLevel[lastChange] != currentLevel[lastChange])
	{
		// Records unrecorded change.
		creatureDiary.writeEntry(creatureName, appendixes[lastChange], lastLevel[lastChange], currentLevel[lastChange], lastDateOfChange[lastChange]);
		recorded = true;
	}

	if (!sorted)
	{
		for (int i = 0; i < appendixes.size(); i++) for (int j = 0; j < appendixes.size() - 1; j++) if (appendixes[j] > appendixes[j + 1])
		{
			swap(appendixes[j], appendixes[j + 1]);
			swap(currentLevel[j], currentLevel[j + 1]);
			swap(lastLevel[j], lastLevel[j + 1]);
		}
	}

	cout << creatureName << "'s status:\n";
	for (int i = 0; i < appendixes.size(); i++)
	{
		if (currentLevel[i] > 0) 
			cout << appendixes[i] << " * " << currentLevel[i] << endl;
	}

	cout << endl;
}

void Creature::PrintLog()
{
	cout << creatureName << "'s log:\n";

	// Checks if an unrecorded change exists.
	if (!recorded && lastLevel[lastChange] != currentLevel[lastChange])
	{
		// Records unrecorded change.
		creatureDiary.writeEntry(creatureName, appendixes[lastChange], lastLevel[lastChange], currentLevel[lastChange], lastDateOfChange[lastChange]);
		recorded = true;
	}

	creatureDiary.outputLog();
	cout << endl;
}