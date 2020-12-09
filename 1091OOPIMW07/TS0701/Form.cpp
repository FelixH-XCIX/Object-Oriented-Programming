#include "Form.h"
#include <cctype>



Form::Form()
{
}


Form::~Form()
{
}

// Intent: to assign new string to the input elements     
// Pre	 : string    
// Post  : input elements are sets
void Form::SetInputWord(string inputWord)
{
	this->input = inputWord;
}

// Intent: process the input elements to array of assci array 
// Pre	 : input elements from the class    
// Post  : array count contain the count of each ascii char
void Form::ProcessInputWord()
{
	for (int i = 0; i < this->input.length(); i++)
	{
		count[isalpha(input[i]) ? (int)toupper(input[i]) : (int)input[i]] += 1;
	}
}

// Intent: to set the source word of text
// Pre	 : file name as string
// Post  : returned assigned as string in fileName
void Form::SetFileName(string fileName)
{
	this->fileName = fileName;
}


// Intent: compare and to load the file 
// Pre	 : elements fileName and input
// Post  : found string pushed back to array of vector
void Form::Load_CompaerWord()
{
	ifstream file;
	string test;
	ofstream ofStream;
	file.open(fileName);
	int freq = 0;

	ofStream.open("sample.out");
	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> test;
			//cout << test << endl;
			int testCount[128] = { 0 };// 0 ~ 25 is alphabet; 26 ~ 36 is 0 ~ 9
			for (int i = 0; i < test.length(); i++)
			{
				testCount[isalpha(test[i]) ? (int)toupper(test[i]) : (int)test[i]] ++;
			}
			bool isYes = true;
			for (int i = 0; i < 128; i++)
			{
				if (testCount[i] > count[i])
				{
					isYes = false;
				}
			}
			if (isYes == true)
			{
				found.push_back(test);
				freq++;
			}
		}
	}

	for (int i = 0; i < freq; i++)
	{
		ofStream << found[i] << endl;
	}

	
	file.close();
	ofStream.close();

}

//print out all of the found words
void Form::PrintFoundWords()
{
	for (int i = 0; i < found.size(); i++)
	{
		cout << found[i] << endl;
	}
}