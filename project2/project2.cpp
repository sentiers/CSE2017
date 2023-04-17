// CSE2017-01 Data Structure
// Project2
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 May 12
//
// project2.cpp
// :Test project2 program


#include "listLnk.cpp"

using namespace std;

void print_help() {
	cout << endl << "Commands" << endl;
	cout << "  P <name>             Create a person record of the specified name." << endl;
	cout << "  F <name1> <name2>    Record that the two specified people are friends." << endl;
	cout << "  U <name1> <name2>    Record that the two specified people are no longer friends." << endl;
	cout << "  L <name>             Print out the friends of the specified person." << endl;
	cout << "  Q <name1> <name2>    Check whether the two people are friends." << endl;
	cout << "  X                    Terminate the program." << endl;
	cout << endl;
}

int main() {
	List<string> microFB(10);
	string str1;
	string str2;
	char cmd;

	cout << "#################################################################################" << endl;
	cout << "###   #######   ########################################         ###        #####" << endl;
	cout << "###  #  ###  #  ########################################  ##########  #####  ####" << endl;
	cout << "###  ##  #  ##  ###  ######    ###  #########   ########         ###       ######" << endl;
	cout << "###  #### ####  ########  ########     ###  #####  #####  ##########  #####  ####" << endl;
	cout << "###  #########  ###  ###  ########  ######  #####  #####  ##########  ######  ###" << endl;
	cout << "###  #########  ###  ######    ###  #########   ########  ##########         ####" << endl;
	cout << "#################################################################################" << endl;

	do {
		print_help();

		cin >> cmd;

		if (cmd == 'P' || cmd == 'p' || cmd == 'L' || cmd == 'l')
			cin >> str1;
		else if (cmd == 'F' || cmd == 'f' || cmd == 'U' || cmd == 'u' || cmd == 'Q' || cmd == 'q')
			cin >> str1 >> str2;

		switch (cmd) {
		case 'P': case 'p':
			microFB.insert(str1);
			break;

		case 'F': case 'f':
			microFB.friends(str1, str2);
			break;

		case 'U': case 'u':
			microFB.unfriends(str1, str2);
			break;

		case 'L': case 'l':
			microFB.printFriendList(str1);
			break;

		case 'Q': case 'q':
			microFB.isFriend(str1, str2);
			break;

		case 'X': case 'x':
			break;

		default:
			cout << "Inactive or Invalid command" << endl;
			break;
		}
	} while (cmd != 'X' && cmd != 'x');

	return 0;
}