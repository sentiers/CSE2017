// CSE2017-01 Data Structure
// Lab 12 - Sorting, Searching, Hash
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 June 2
//
// login.cpp
// :In-lab 1 program that reads in username/login pairs and then
//  performs authentication of usernames until EOF is encountered.


#include <string>
#include <iostream>
#include <fstream>
#include "hashtbl.cpp"

using namespace std;

//This will be the data stored in the HashTbl (class DT)
struct Password
{
	void setKey(string newKey) { username = newKey; }
	string getKey() const { return username; }

	//this hash converts a string to an integer
	int hash(const string str) const
	{
		int val = 0;

		for (int i = 0; i < str.length(); i++)
			val += str[i];
		return val;
	}
	string username,
		password;
};

int main()
{
	HashTbl<Password, string> passwords(10);
	Password tempPass;
	string name,      // user-supplied name
		pass;      // user-supplied password

	//*********************************************************
	// Step 1: Read in the password file
	//*********************************************************

	//**add line here to read in the password file
	ifstream passFile("password.dat");

	if (!passFile)
	{
		cout << "Unable to open 'password.dat'!" << endl;
		return 1;
	}

	while (passFile >> tempPass.username >> tempPass.password
		&& !passwords.isFull())
	{
		//**add line here to insert passwords into the HashTbl
		passwords.insert(tempPass);
	}

	//**add line here to show (print) the HashTbl
	passwords.showStructure();

	//*********************************************************
	// Step 2: Prompt for a Login and Password and check if valid
	//*********************************************************
	cout << "Login: ";
	while (cin >> name)  // to quit, type CTRL Z in Visual C++
	{
		//**add line here to retrieve user from HashTbl
		bool found = passwords.retrieve(name, tempPass);

		cout << "Password: ";
		cin >> pass;

		//**add lines here to compare retrieved user password to 
		//**input password and print "Authentication failure"
		//**or "Authentication successful"
		if ((tempPass.password == pass) && found) {
			cout << "Authentication successful" << endl;
		}
		else {
			cout << "Authentication failure" << endl;
		}

		cout << "Login: ";
	}

	cout << endl;
	return 0;

}

