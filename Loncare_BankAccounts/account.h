#pragma once

 class account
{
	 // variables
	private:
		float charge = 0, interest = 0, balance = 0;
		int withdraw_num = 0, deposit_num = 0;
	// function prototypes
	public:
		account(float, float);
		virtual void deposit(float);
		virtual void withdraw(float);
		virtual void calcint();
		virtual void monthlyproc();
	// methods to acces data
		float getCharge();
		void setCharge(float);
		float getInterest();
		void setInterest(float);
		float getBalance();
		void setBalance(float);
		int getWithdrawnum();
		void setWithdrawnum(int);
		int getDespositnum();
		void setDespoitnum(int);
};

