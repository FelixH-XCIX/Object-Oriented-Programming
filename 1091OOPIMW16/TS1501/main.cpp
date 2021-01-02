#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <iterator>
#include <string>

using namespace std;

int main()
{
	set<string> s1;
	string x;
	ifstream inFile;

	inFile.open("name.txt");

	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}


	while(getline(inFile,x))
	{
		s1.insert(x);
	}
	set<string>::iterator itr;
	for (itr = s1.begin(); itr != s1.end(); ++itr)
	{
		cout << *itr << endl;
	}
	
	return 0;
}