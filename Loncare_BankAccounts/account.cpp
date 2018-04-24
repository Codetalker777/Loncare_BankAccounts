#include "stdafx.h"
#include "account.h"
//  constructor
account::account(float bal, float rate) {

	account::interest = rate;
	account::balance = bal;
}
void account::deposit(float dep) {

	account::balance += dep;
	account::deposit_num++;
}

void account::withdraw(float money) {

	account::balance -= money;
	account::withdraw_num++;
}

void account::calcint() {

	if (account::balance > 0) {
		float monthly_rate, monthly_gain;
		monthly_rate = account::interest / 12;
		monthly_gain = monthly_rate * account::balance;
		account::balance += monthly_gain;
	}
}

void account::monthlyproc() {
	account::balance -= account::charge;
	account::calcint();
	account::withdraw_num = 0;
	account::deposit_num = 0;
	account::charge = 0;

}

float account::getCharge() {
	return account::charge;
}

void account::setCharge(float amount) {
	account::charge = amount;
}

float account::getInterest() {

	return account::interest;
}

void account::setInterest(float amount) {
	account::interest = amount;
}

float account::getBalance() {
	return account::balance;
}
void account::setBalance(float amount) {
	account::balance = amount;
}

int account::getDespositnum() {
	return account::deposit_num;
}

void account::setDespoitnum(int amount) {
	account::deposit_num = amount;
}

int account::getWithdrawnum() {
	return account::withdraw_num;
}

void account::setWithdrawnum(int amount) {
	account::withdraw_num = amount;
}