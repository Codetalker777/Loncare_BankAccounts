#pragma once
#include "account.h"
class checking_account : public account
{
	// function prototypes
public:
	checking_account(float, float);
	void withdraw(float);
	void deposit(float);
	void monthlyproc();
	float returnCharge();
};