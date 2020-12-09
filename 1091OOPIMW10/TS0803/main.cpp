#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	int N;
	while (cin >> N)
	{
		vector<int> data;
		for (int i = 0; i < N; i++)
		{
			data.push_back(0);
		}

		int n;
		cin >> n;
		for (int c = 0; c < n; c++)
		{
			string command;
			cin >> command;
			if (command == "Set")
			{
				int position;
				string type;
				cin >> position >> type;

				if (type == "char")
				{
					int value;
					cin >> value;
					if (position + 1 > N)
					{
						cout << "Violation Access." << endl;
						continue;
					}

					data[position] = value;
				}
				else if (type == "short")
				{
					int value;
					cin >> value;
					for (int i = position; i < position + 2; i++)
					{
						if (i >= N)
						{
							cout << "Violation Access." << endl;
							break;
						}
						data[i] = value % 256;
						value /= 256;
					}
				}
				else if (type == "int")
				{
					unsigned int value;
					cin >> value;
					for (int i = position; i < position + 4; i++)
					{
						if (i >= N)
						{
							cout << "Violation Access." << endl;
							break;
						}
						data[i] = value % 256;
						value /= 256;
					}
				}
				else if (type == "String")
				{
					string value;
					cin >> value;
					for (int i = 0; i < value.length(); i++)
					{
						if (position + i >= N)
						{
							cout << "Violation Access." << endl;
							break;
						}
						data[position + i] = (int)value[i];
					}
				}
				else
					cout << "Violation Access." << endl;
			}
			else if (command == "Get")
			{
				int position;
				string type;
				cin >> position >> type;

				if (position < 0 || position >= N)
				{
					cout << "Violation Access." << endl;
					continue;
				}

				if (type == "char")
				{
					cout << (data[position]) << endl;
				}
				else if (type == "short")
				{
					int ans = 0;
					bool isvalid = true;
					for (int i = position; i < position + 2; i++)
					{
						if (i < N)
							ans += pow(256, (i - position)) * data[i];
						else
						{
							isvalid = false;
							cout << "Violation Access." << endl;
							break;
						}
					}
					if (isvalid)
						cout << ans << endl;
				}
				else if (type == "int")
				{
					unsigned int ans = 0;
					bool isvalid = true;
					for (int i = position; i < position + 4; i++)
					{
						if (i < N)
							ans += pow(256, (i - position)) * data[i];
						else
						{
							isvalid = false;
							cout << "Violation Access." << endl;
							break;
						}
					}
					if (isvalid)
						cout << ans << endl;
				}
				else if (type == "String")
				{
					int i = position;
					while (i < N)
					{
						if (data[i] == 0) break;
						cout << (char)data[i];
						i++;
					}
					cout << endl;
				}
				else
					cout << "Violation Access." << endl;
			}
		}
	}
}