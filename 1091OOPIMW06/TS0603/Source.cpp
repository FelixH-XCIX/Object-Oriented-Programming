#include "NumberGame.h"


void print(vector<int> x)
{
	for (int i = 0; i < x.size(); i++)
		cout << i << " " << x[i] << endl;
}

void printvs(vector<string> x)
{
	for (int i = 0; i < x.size(); i++)
		cout << i << " " << x[i] << endl;
}

void NumberGame::SetInput(int x)
{
	input = to_string(x);
}

void NumberGame::SetFileName(string s)
{
	filename = s;
}

void NumberGame::ProcessInput()
{
	vector<int> numberTemp;
	for (int i = 0; i < input.size(); i++)
	{
		int temp = (int)input[i] - 48;
		//cout << temp << endl;
		numberTemp.push_back(temp);
	}

	//cout << input.size() << endl;
	//print(numberTemp);

	for (int i = 0; i < input.size(); i++)
	{
		if (i == input.size() - 1)
			break;
		for (int j = i + 1; j < input.size(); j++)
		{
			if (numberTemp[i] == 0 || numberTemp[i] == 1)
				break;
			else
			{
				int atemp = numberTemp[i] * numberTemp[j];
				//cout << i << " " << j << " " << numberTemp[i] << " " << numberTemp[j] << endl;
				//cout << atemp << " atemps of " << i << endl;
				numberTemp.push_back(atemp);
			}
		}
	}
	//print(numberTemp);

	for (int i = 0; i < numberTemp.size(); i++)
	{
		list.push_back(to_string(numberTemp[i]));
	}

	//printvs(list);
}

void NumberGame::LoadNumberList()
{
	ifstream inFile;
	string x;
	inFile.open(filename.c_str());
	while (inFile >> x)
	{
		inputs.push_back(x);
	}
}

void NumberGame::PrintAllValid()
{
	int breaker = 0;
	int pos = 0;
	printvs(list);
	cout << "list size = " << list.size() << endl;
	for (int i = 0; i < inputs.size(); i++)
	{
		cout << i << endl;
		if (breaker == list.size())
			break;
		else if (list[pos] == inputs[i])
		{
			cout << inputs[i] << "\t" << list[pos] << "\t" << breaker << " " << pos << endl;
			cout <<  " output : "<< inputs[i] << endl;
			breaker++;
			pos++;
			i = 0;
		}
	}
}

void NumberGame::Reset()
{
	list.clear();
	numbers.clear();
	inputs.clear();
	input.clear();
	filename.clear();

}