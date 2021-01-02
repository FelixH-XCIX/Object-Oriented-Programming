#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;



class Item{
public:
	unsigned int price;
	int id;

	Item& operator=(const Item& source)
	{
		price = source.price;
		id = source.id;
		return *this;
	}

	Item(int sid, unsigned int sprice)
	{
		id = sid;
		price = sprice;
	}

	Item()
	{
		
	}
};

class Student {
public:
	int id;
	unsigned int money;
	int itemCount;
	
	Item* sitem = new Item[100];


	Student& operator=(const Student& source)
	{
		id = source.id;
		money = source.money;
		sitem = source.sitem;
	}

	Student(int sid, unsigned int smoney)
	{
		id = sid;
		money = smoney;
	}

	Student()
	{}

	void sort()
	{
		int i, j;
		for (i = 0; i < itemCount - 1; i++)
			// Last i elements are already in place  
			for (j = 0; j < itemCount - i - 1; j++)
				if (sitem[j].id > sitem[j + 1].id)
				{
					swap(sitem[j], sitem[j + 1]);
				}
		
	}

	void sortPrice(int pos, int size)
	{

		int i, j;
		for (i = 0; i < size - 1; i++)
			for (j = 0; j < size - i - 1; j++)
			{
				//cout << sitem[j + pos].price << " " << sitem[j + 1 + pos].price << endl;
				if (sitem[j + pos].price > sitem[j + 1 + pos].price)
				{
					swap(sitem[j + pos], sitem[j + 1 + pos]);
				}
			}
	}

	void show()
	{
		cout << "$" << money << "." << endl;
		sort();
		//cout << itemCount << " " << endl;
		int itemCountperid[100] = { 0 };

		for (int i = 0; i <= itemCount; i++)
		{
			for (int j = 0; j <= itemCount; j++)
			{
				if (i == sitem[j].id)
					itemCountperid[i]++;
			}
		}


		for (int i = 0; i <= itemCount; i++)
		{
			int pos;
			if (itemCountperid[i] >= 2)
			{
				for(int j = 0; j <= itemCount ; j++)
					if (sitem[j].id == i)
					{
						pos = j;
						break;
					}
				sortPrice(pos,itemCountperid[i]);
			}
		}

		for (int i = 0; i <= itemCount; i++)
		{
			//cout << itemCount << " " << endl;
			if(sitem[i].id >= 0 && (sitem[i].price > 0 && sitem[i].price < 480000))
				cout << "ID " << sitem[i].id << " $" << sitem[i].price  << endl;
		}
	}
};

int main()
{
	int N, M;
	cin >> N >> M;

	int storeCount = 0;
	Student* stu = new Student[100];
	Item* storage = new Item[100];
	vector<int> itemCountr;

	//student input
	for (int j = 0; j < N; j++)
	{
		stu[j].id = j;
		unsigned int temp;
		cin >> temp;
		stu[j].money = temp;
		itemCountr.push_back(0);
	}

	//item input
	for (int i = 0; i < M; i++)
	{
		unsigned int temp;
		cin >> temp;
		storage[i].id = i;
		storage[i].price = temp;
		storeCount++;
	}
	cin.clear();
	

	string input;
	while (getline(cin, input))
	{
		stringstream ss;
		ss << input;
		string command;
		ss >> command;
		if (command == "buy")
		{
			int sid, iid, pos;
			ss >> sid >> iid;
			bool sfound = false;
			for (int i = 0; i < N; i++)
			{
				if (sid == stu[i].id)
				{
					sfound = true;
					pos = i;
					break;
				}
			}

			if (sfound)
			{
				bool hasMoney = (stu[pos].money > storage[iid].price) ? true : false;
				if (hasMoney)
				{
					stu[pos].money -= storage[iid].price;
					int tempp = storage[iid].price;
					tempp -= 10;
					Item boughtItem = Item(iid, tempp);
					stu[pos].sitem[itemCountr[sid]] = boughtItem;
					itemCountr[sid]++;

					stu[pos].itemCount = itemCountr[sid];

				}
				else
				{
					cout << "Student " << sid << " doesn't have enough money." << endl;
				}
				
			}
		}

		else if (command == "trade")
		{
			bool exist = false;
			int itemPos = 0;
			int sid1, sid2, iid, min, max;
			//case is that there are no invalid input in the student id and item id
			ss >> sid1 >> sid2 >> iid >> min >> max;

			for (int i = 0; i <= itemCountr[sid2]; i++)
			{
				if (stu[sid2].sitem[i].id != iid) 
					continue;
				
				if((stu[sid2].sitem[i].price >= min) && (stu[sid2].sitem[i].price <= max))
				{
					exist = true;
					itemPos = i;
					break;
				}
			}

			if (exist)
			{
				//money transfer
				if(stu[sid1].money < stu[sid2].sitem[itemPos].price)
					cout << "Student " << sid1 << " doesn't have enough money." << endl;
				else
				{
					stu[sid2].money += stu[sid2].sitem[itemPos].price;
					stu[sid1].money -= stu[sid2].sitem[itemPos].price;

					//item value decrease
					stu[sid2].sitem[itemPos].price -= 10;
					stu[sid1].sitem[itemCountr[sid1]] = stu[sid2].sitem[itemPos];
					stu[sid2].sitem[itemPos].id = -1;

					itemCountr[sid1]++;
					stu[sid1].itemCount = itemCountr[sid1];

				}
			}
			else
			{
					cout << "Student " << sid2 << " doesn't have this item." << endl;
			}

		}
		
		else if (command == "sell")
		{
			int sid, iid, price;
			ss >> sid >> iid >> price;
			int itemPos = 0;
			bool exist = false;
			
			for (int i = 0; i <= itemCountr[sid]; i++)
			{
				if ((stu[sid].sitem[i].id == iid) && (stu[sid].sitem[i].price == price))
				{
					exist = true;
					itemPos =  i;
				}
			}

			if (exist)
			{
				stu[sid].money += price;
				stu[sid].sitem[itemPos].id = -1;
			}
			else
				cout << "Student " << sid << " doesn't have this item." << endl;
		}

		else if (command == "show")
		{
			int sid;
			ss >> sid;
			cout << "Student " << sid << " has ";
			stu[sid].show();
		}

		else  if (command == "end")
		{
			break;
		}
	}
}