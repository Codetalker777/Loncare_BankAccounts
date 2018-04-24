#include "stdafx.h"
#include "saving_account.h"
#include "account.h"
#include "iostream"

//constrcutor
saving_account::saving_account(float bal, float rate) :
	account(bal, rate) {
	if (bal < 25) {
		saving_account::status = false;
	}
	else {
		saving_account::status = true;
	}
}
// implementation
void saving_account::deposit(float money) {
	if (status == false) {
		account::deposit(money);
		if (account::getBalance() >= 25) {
			status = true;
		}
	}
	else {
		account::deposit(money);
	}

}
// implementation
void saving_account::withdraw(float money) {

	if (saving_account::status == false) {

		std::cout << "ERROR: Account is inactive \n";
	}
	else {
		account::withdraw(money);
		if (account::getBalance() < 25) {
			saving_account::status = false;
		}
	}

}
// implementation
void saving_account::monthlyproc() {

	float charges = 0;

	if (account::getWithdrawnum() > 4) {
		charges = 1 * (account::getWithdrawnum() - 4);
		account::setCharge(charges);
	}

	if ((account::getBalance() - account::getCharge()) < 25) {

		saving_account::status = false;
	}

	account::monthlyproc();
}
// access method for status varuables
bool saving_account::getStatus() {
	return saving_account::status;
}

void saving_account::setStatus(bool change) {
	saving_account::status = change;
}
// returns amount of charges to be taken for the month
float saving_account::returnCharge() {
	float charges = 0;

	if (account::getWithdrawnum() > 4) {
		charges = 1 * (account::getWithdrawnum() - 4);
		return charges;
	}
	else {
		return 0;
	}
}