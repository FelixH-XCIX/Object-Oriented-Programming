#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	int size;
	vector<string>name, sal, bon;
	string names, sals, bons;

	while (cin >> size)
	{
		for (int i = 0; i < size; i++)
		{
			cin >> names >> sals >> bons;
			name.push_back(names);
			sal.push_back(sals);
			bon.push_back(bons);
		}



		int nmax = 0, smax = 0, bmax = 0;
		string tempn = { 0 }, temps = { 0 }, tempb = { 0 };

		for (int i = 0; i < size; i++)
		{
			if (name[i].size() > tempn.size())
			{
				tempn = name[i];
				nmax = tempn.size();
			}

			if (sal[i].size() > temps.size())
			{
				temps = sal[i];
				smax = temps.size();
			}

			if (bon[i].size() > tempb.size())
			{
				tempb = bon[i];
				bmax = tempb.size();
			}
		}

		for (int i = 0; i < size; i++)
		{
			int diffn = nmax - name[i].size();
			int diffs = smax - sal[i].size();
			int diffb = bmax - bon[i].size();

			while (diffn > 0)
			{
				cout << " ";
				diffn--;
			}
			cout << name[i] << "|";
			cout << "  ";

			while (diffs > 0)
			{
				cout << " ";
				diffs--;
			}
			cout << sal[i];
			cout << "|" << "  ";

			while (diffb > 0)
			{
				cout << " ";
				diffb--;
			}

			cout << bon[i] << endl;
		}

		name.clear();
		bon.clear();
		sal.clear();
	}

	return 0;

}