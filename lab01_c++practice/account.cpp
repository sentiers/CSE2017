// CSE2017-01 Data Structure
// Lab 01 - C++ Practice
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 March 10
//
// account.cpp
// :Bank account information manage/display program

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

class bank
{
	char name[20];
	int acno;
	char actype[4];
	float balance;

public:
	void init(); //initialize new account info
	void deposit(); //deposit money
	void withdraw(); // withdraw money
	void disp_det(); // display account info
};

//member functions of bank class
void bank::init()
{
	cout << endl;
	cout << "New Account" << endl;
	cout << "Enter the Name of the depositor : ";
	cin >> name;
	cout << "Enter the Account Number : ";
	cin >> acno;
	cout << "Enter the Account Type : (CURR / SAVG / FD / RD / DMAT) ";
	cin >> actype;
	cout << "Enter the Amount to Deposit : ";
	cin >> balance;
}

void bank::deposit()
{
	float amount;
	cout << endl;
	cout << "Depositing" << endl;
	cout << "Enter the amount to deposit : ";
	cin >> amount;
	balance += amount;
}

void bank::withdraw()
{
	float amount;
	cout << endl;
	cout << "Withdrawal" << endl;
	cout << "Enter the amount to withdraw : ";
	cin >> amount;
	balance -= amount;
}

void bank::disp_det()
{
	cout << endl;
	cout << "Account Details" << endl;
	cout << "Name of the depositor : " << name << endl;
	cout << "Account Number      : " << acno << endl;
	cout << "Account Type      : " << actype << endl;
	cout << "Balance        : $" << balance << endl;
}

// main function , exectution starts here
void main(void)
{
	// clrscr();
	bank obj;
	int choice = 1;
	while (choice != 0)
	{
		cout << "Enter 0 to exit\n1. Initialize a new acc.\n2. Deposit\n3. Withdraw\n4. See A / c Status\n";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 0:
			obj.disp_det();
			cout << "EXITING PROGRAM.";
			break;
		case 1:
			obj.init();
			break;
		case 2:
			obj.deposit();
			break;
		case 3:
			obj.withdraw();
			break;
		case 4:
			obj.disp_det();
			break;
		default:
			cout << "Illegal Option" << endl;
		}
	}
	_getch();
}