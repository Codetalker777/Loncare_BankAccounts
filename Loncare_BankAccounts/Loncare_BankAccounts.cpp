// Loncare_BankAccounts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "account.h"
#include "saving_account.h"
#include "checking_account.h"
#include "iostream"
#include "iomanip"
#include "conio.h"

using namespace std;

// checks if entry is less than zero
bool validcheck(float);

int main()
{
	// variables
	int i = 0;
	float amount;
	saving_account savings(0, 0.06);
	checking_account checking(0, 0.02);

	do {

		// menu
		cout << "********Bank Account Menu********\n\n";
		cout << "1. Saving Account Deposit \n";
		cout << "2. Checking Account Deposit \n";
		cout << "3. Saving Account Withdraw \n";
		cout << "4. Checking Account Withdraw \n";
		cout << "5. Update and Display Account Statistics \n";
		cout << "6. Exit \n\n";
		cout << "Your Choice please:(1-6) ";
		cin >> i;
		//ensures that the input is valid
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a Value between (1-6) \n";
			cout << "Your Choice please:(1-6) ";
			cin >> i;
		}

		// tasks based on choice
		switch (i) {
		case 1: 
			cout << "Enter Amount to Deposit $";
			cin >> amount;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Enter a valid number to Deposit $";
				cin >> amount;
			}
			// loops until a valid entry is made
			while (validcheck(amount) == false) {
				cout << "Please enter a positive value $";
				cin >> amount;
			}
			savings.deposit(amount);
			break;
		case 2:
			cout << "Enter Amount to Deposit $";
			cin >> amount;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Enter a valid number to Deposit $";
				cin >> amount;
			}
			while (validcheck(amount) == false) {
				cout << "Please enter a positive value $";
				cin >> amount;
			}
			checking.deposit(amount);
			break;
		case 3:
			cout << "Enter Amount to Withdraw $";
			cin >> amount;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Enter a valid number to Withdraw $";
				cin >> amount;
			}
			while (validcheck(amount) == false) {
				cout << "Please enter a positive value $";
				cin >> amount;
			}
			savings.withdraw(amount);
			break;
		case 4:
			cout << "Enter Amount to Withdraw $";
			cin >> amount;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Enter a valid number to Withdraw $";
				cin >> amount;
			}
			while (validcheck(amount) == false) {
				cout << "Please enter a positive value $";
				cin >> amount;
			}
			checking.withdraw(amount);
			break;
		case 5: //prints out statistics
			cout << "SAVING ACCOUNT MONTHLY STATISTICS: \n";
			cout << "Withdraws:     " << fixed << setw(10) << savings.getWithdrawnum() << endl;
			cout << "Deposits:      " << fixed << setw(10) << savings.getDespositnum() << endl;
			cout << "Charges:       " << fixed << setw(10) << setprecision(2) << savings.returnCharge() << endl << endl;
			savings.monthlyproc();
			cout << "Ending Balance:" << fixed << setw(10) << setprecision(2) << savings.getBalance() << endl << endl;
			cout << "Press a key to continue...";
			_getch();
			cout << "\n\nCHEQUING ACCOUNT MONTHLY STATISTICS: \n";
			cout << "Withdraws:     " << fixed << setw(10) << checking.getWithdrawnum() << endl;
			cout << "Deposits:      " << fixed << setw(10) << checking.getDespositnum() << endl;
			cout << "Charges:       " << fixed << setw(10) << setprecision(2) << checking.returnCharge() << endl << endl;
			checking.monthlyproc();
			cout << "Ending Balance:" << fixed << setw(10) << setprecision(2) << checking.getBalance() << endl << endl;
			break;
		case 6: // terminate
			break;
		default: //incorrect entry
			cout << "Please enter a Value between (1-6) \n";
			break;
		}

			
	} while (i != 6);

	return 0;
}

// if number is greater than zero returns true else false
bool validcheck(float number) {
	
	if (number >= 0) {
		return true;
	}
	else {
		return false;
	}
}

