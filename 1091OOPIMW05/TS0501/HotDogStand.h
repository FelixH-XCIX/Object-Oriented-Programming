#pragma once
#include <string>
#include <iostream>

using namespace std;

class HotDogStand
{
public:
	HotDogStand();
	HotDogStand(string id);
	HotDogStand(string id, int amount);
	~HotDogStand();
	void justSold();
	void print();
	int thisStandSoldAmount();
	static int allStandSoldAmount();
private:
	string standId;
	int hotDogSellAmount;
	static int totalSellAmount;
};

