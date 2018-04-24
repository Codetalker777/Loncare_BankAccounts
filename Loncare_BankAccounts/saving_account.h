#pragma once
#include "account.h"
#include "iostream"
class saving_account:  public account
{
	// additional variable
private: bool status;
public:
	// function prototypes
	saving_account(float, float);
	void deposit(float);
	void withdraw(float);
	void monthlyproc();
	bool getStatus();
	void setStatus(bool);
	float returnCharge();
};

