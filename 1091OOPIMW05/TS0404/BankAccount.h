#include <iostream>
using namespace std;

class BankAccount {
private:
	int balance;
	static int total;
public:
	static long int allMoneyInBank;
	BankAccount();
	BankAccount(int input);
	void withdraw(int output);
	void save(int input);
	int getBalance();
	static int getAllMoneyInBank();
};