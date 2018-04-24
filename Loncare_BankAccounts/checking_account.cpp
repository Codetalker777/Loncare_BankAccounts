#include "stdafx.h"
#include "checking_account.h"
#include "account.h"
#include "iostream"
// constructor
checking_account::checking_account(float bal, float rate) : account(bal,rate)
{
}
// implementation
void checking_account::deposit(float money) {
	account::deposit(money);
}
// implementation
void checking_account::withdraw(float money) {
	float bal;
	if (account::getBalance() - money < 0) {
		bal = account::getBalance() - 15;
		account::setBalance(bal);
	}
	else {
		account::withdraw(money);
	}
}
// implementation
void checking_account::monthlyproc() {

	float charges = 0;

	charges = static_cast<float>(account::getWithdrawnum()) * 0.1 + 5;

	account::setCharge(charges);

	account::monthlyproc();
}
// returns the monthly charges
float checking_account::returnCharge() {
	float charges = 0;
	charges = static_cast<float>(account::getWithdrawnum()) * 0.1 + 5;
	return charges;
}