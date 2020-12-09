#include "BankAccount.h"

using namespace std;
long int BankAccount::allMoneyInBank = 0;

BankAccount::BankAccount()
{
	balance = 0;
	allMoneyInBank += 0;
}

BankAccount::BankAccount(int input)
{
	balance = input;
	allMoneyInBank += input;
}

int BankAccount::getBalance() 
{
	return balance;
}

void BankAccount::withdraw(int output)
{
	balance -= output;
	allMoneyInBank -= output;
}

void BankAccount::save(int input)
{
	balance += input;
	allMoneyInBank += input;
}

int BankAccount::getAllMoneyInBank()
{
	return allMoneyInBank;
}

