#include <iostream>
#include <string>
#include <vector>
using namespace std;

int processed(int x)
{
	int rem = x;
	if (x <= -26 || x >= 26)
	{
		rem = (x < 0) ? (x % -26) : (x % 26);
		return rem;
	}

	return rem;
}

void printv(vector<char> x)
{
	for (int i = 0; i < x.size(); i++)
		cout << x[i];

}

int main()
{
	string input;
	vector<char>alphabet{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	vector<char>hasil;
	vector<char> inputx;

	while (getline(cin, input))
	{
		hasil.clear();
		inputx.clear();
		int key;
		cin >> key;
		key = processed(key);
		//cout << key << " this is key" << endl;
		if (key == 0)
			cout << input;
		else {
			for (int i = 0; i < input.length(); i++)
			{
				inputx.push_back(input[i]);
				string s(hasil.begin(),hasil.end());
				//cout << s << endl;
				//if (s == "rpthpgrxe")
					//printv(inputx);
				if (isalpha(input[i]))
				{

					//cout << input[i] - 'a'<< endl;
					int pos = ( input[i] - 'a' ) + key;
					//cout << pos << " ";
					 if (pos < 0) 
					{
						char x = 26 + pos;
						cout << alphabet[x];
						//hasil.push_back(alphabet[x]);
						continue;
					}
					else if (pos > 25)
					{
						char x = pos % 26;
						cout << alphabet[x];
						//hasil.push_back(alphabet[x]);
						continue;
					}
					else
					{
						cout << alphabet[pos];
						//hasil.push_back(input[i]);
						continue;
					}
					
				}
				else if( input[i] == ' ')
					cout << " ";
			}
		}

		cout << endl;
		cin.ignore();
	}
}