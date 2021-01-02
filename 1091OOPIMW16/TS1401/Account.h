#pragma once

struct InsufficientFunds
{
	
};

struct NegativeDeposit
{

};

class Account
{
public:
	double balance;
	Account() { balance = 0; }
	Account(double initialDeposit) { balance = initialDeposit; }
	double getBalance() { return balance; }

	//returns new balance or -1 if error 
	double deposit(double amount)
	{
		if (amount > 0) balance += amount;
		else {
			throw NegativeDeposit();
			//return -1;
		}
		return balance;
	}

	//return new balance or -1 if invalid amount 
	double withdraw(double amount)
	{
		if ((amount > balance) || (amount < 0))
		{
			throw InsufficientFunds();
			//return -1;
		}
		else balance -= amount;
		return balance;
	}
};

