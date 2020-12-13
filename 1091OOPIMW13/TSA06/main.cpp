#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<string>&x,vector<string>&n, vector<string> &g, vector<double>&h, vector<double>&w, int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (x[j] > x[j + 1])
			{
				x[j].swap(x[j + 1]);
				n[j].swap(n[j + 1]);
				g[j].swap(g[j + 1]);
				swap(h[j], h[j + 1]);
				swap(w[j], w[j + 1]);
			}
}

int main()
{
	string input;
	int size = 0;
	vector<string>name, sid, gen;
	vector<double>height, weight;
	while (getline(cin, input))
	{
		stringstream ss;
		ss << input;
		string command;
		ss >> command;

		//add command
		if (command == "Add")
		{
			if (size == 0)
			{
				string temp;
				double num;
				ss >> temp;
				sid.push_back(temp);
				ss >> temp;
				name.push_back(temp);
				ss >> temp;
				gen.push_back(temp);
				ss >> num;
				height.push_back(num);
				ss >> num;
				weight.push_back(num);
				size++;
			}
			else
			{
				bool dup = false;
				string temp;
				double num;
				ss >> temp;
				//cout << temp << " " << size << endl;
				for (int i = 0; i < size; i++)
				{
					if (temp.compare(sid[i]) == 0)
					{
						
						cout << "The student's ID is duplicate." << endl;
						dup = true;
						break;
					}
				}

				if(!dup)
				{
					sid.push_back(temp);
					ss >> temp;
					name.push_back(temp);
					ss >> temp;
					gen.push_back(temp);
					ss >> num;
					height.push_back(num);
					ss >> num;
					weight.push_back(num);
					size++;
					bubbleSort(sid, name, gen, height, weight, size);
				}
			}
		}

		//del command
		else if (command == "Del")
		{
			bool found = false;
			int pos = 0;
			string temp;
			ss >> temp;
			for (int i = 0; i < size; i++)
			{
				if (temp.compare(sid[i]) == 0)
				{
					found = true;
					pos = i;
				}
			}

			if (found)
			{
				sid.erase(sid.begin() + pos);
				name.erase(name.begin() + pos);
				gen.erase(gen.begin() + pos);
				height.erase(height.begin() + pos);
				weight.erase(weight.begin() + pos);
				size--;
			}
			else
			{
				cout << "Student Not Found." << endl;
			}
		}

		//edit command
		else if (command == "Edit")
		{
			bool found = false;
			int pos = 0;
			double numt;
			string temp;
			ss >> temp;
			for (int i = 0; i < size; i++)
			{
				if (temp.compare(sid[i]) == 0)
				{
					found = true;
					pos = i;
				}
			}

			if (found)
			{
				ss >> temp;
				if (temp == "Name")
				{
					ss >> temp;
					name[pos] = temp;
				}
				else if (temp == "Gender")
				{
					ss >> temp;
					gen[pos] = temp;
				}
				else if (temp == "Height")
				{
					ss >> numt;
					height[pos] = numt;
				}
				else if (temp == "Weight")
				{
					ss >> numt;
					weight[pos] = numt;
				}
			}
			else
			{
				cout << "Student Not Found." << endl;
			}

		}

		//find command
		else if (command == "Find")
		{
			bool found = false;
			int pos = 0;
			double numt;
			string temp;
			ss >> temp;
			for (int i = 0; i < size; i++)
			{
				if (temp.compare(sid[i]) == 0)
				{
					found = true;
					pos = i;
					break;
				}
				
			}

			if (found)
			{
				cout << sid[pos] << '\t' << name[pos] << '\t' << gen[pos] << '\t' << height[pos] << '\t' << weight[pos] << endl;
			}
			else
			{
				cout << "Student Not Found." << endl;
			}
		}

		//command list
		else if (command == "List")
		{
			for (int i = 0; i < size; i++)
			{
				cout << sid[i] << '\t' << name[i] << '\t' << gen[i] << '\t' << height[i] << '\t' << weight[i] << endl;
			}
		}
	}

	return 0;
}