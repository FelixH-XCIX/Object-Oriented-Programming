#pragma once
#include <string>		
#include <iostream>	
#include <vector>		
#include <fstream>	
#include <map>

using namespace std;

class Form
{
private:
	string input;//輸入的字
	string fileName;//檔案名稱
	int count[128] = { 0 };
	vector<string> found;
public:
	Form();
	~Form();
	void SetInputWord(string inputWord);//設定Input
	void ProcessInputWord();//處理 Input 的資訊
	void SetFileName(string fileName);//設定檔案名稱
	void Load_CompaerWord();//讀檔並且比較
	void PrintFoundWords();//印出符合的字
};

