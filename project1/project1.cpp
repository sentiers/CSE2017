// CSE2017-01 Data Structure
// Project1 - List(Array)
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 April 15
//
// project1.cpp
// :Test project1 program


#include "listarr.h"

using namespace std;

int main() {
	List personList;
	char cmd;

	do {
		cout << "Commands:" << endl;
		cout << "    R: read from a file" << endl;
		cout << "    +: add a new entry" << endl;
		cout << "    -: remove an entry" << endl;
		cout << "    W: write to a file" << endl;
		cout << "    M: select a month" << endl;
		cout << "    Q: quit the program" << endl;
		cout << "    ";
		cin >> cmd;

		switch (cmd) {
		case 'R': case 'r':
			personList.read();
			personList.showInfo();
			break;

		case '+':
			personList.insert();
			personList.showInfo();
			break;

		case '-':
			personList.remove();
			personList.showInfo();
			break;

		case 'W': case 'w':
			personList.write();
			break;

		case 'M': case 'm':
			personList.showInfoByMonth();
			break;

		case 'Q': case 'q':
			break;

		default:
			cout << "Invalid command" << endl;
		}
	} while (cmd != 'Q' && cmd != 'q');

	return 0;
}
