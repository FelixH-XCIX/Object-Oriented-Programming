#include "HotDogStand.h"


int HotDogStand::totalSellAmount = 0;

HotDogStand::HotDogStand()
{
}

HotDogStand::HotDogStand(string id)
{
	standId = id;
	hotDogSellAmount = 0;
	totalSellAmount += 0;
}

HotDogStand::HotDogStand(string id, int amount)
{
	standId = id;
	hotDogSellAmount = amount;
	totalSellAmount += amount;
}


HotDogStand::~HotDogStand()
{
}

void HotDogStand::justSold()
{
	hotDogSellAmount++;
	totalSellAmount++;
}

void HotDogStand::print()
{
	cout << standId << " " << thisStandSoldAmount() << endl;
}

int HotDogStand::thisStandSoldAmount()
{
	return hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount()
{
	return totalSellAmount;
}

