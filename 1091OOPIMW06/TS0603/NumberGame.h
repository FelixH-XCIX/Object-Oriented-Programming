#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class NumberGame {
public:
	void SetInput(int);
	void ProcessInput();
	void SetFileName(string);
	void LoadNumberList();
	void PrintAllValid();
	void Reset();

private:
	vector<string> list, numbers, inputs;
	string input, filename;
};