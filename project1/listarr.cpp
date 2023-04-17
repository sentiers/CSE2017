// CSE2017-01 Data Structure
// Project1 - List(Array)
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 April 15
//
// listarr.cpp
// :Array implementation of the List ADT


#include "listarr.h"

using namespace std;

List::List(int maxNumber) : maxSize(maxNumber), size(0), cursor(-1) {
	personData = new Person[maxSize];
}

List:: ~List() {
	delete[] personData;
}

void List::read() {
	string fileName;
	string line;

	cin.ignore();
	clear(); // prepare to read new file

	cout << "    Enter the name of the file: ";
	getline(cin, fileName);

	ifstream textFile(fileName + ".txt");
	if (!textFile) {
		cout << "    Unable to open " + fileName << endl;
	}
	else {
		while (textFile.is_open()) {
			if (isFull()) { // when the number of people reached maxsize
				cout << "    List is Full!" << endl;
				textFile.close();
				break;
			}
			else {
				if (getline(textFile, line)) { // If there is new data
					cursor++;
					personData[cursor].name = line;

					getline(textFile, line);
					personData[cursor].phoneNum = line;

					getline(textFile, line);
					personData[cursor].birthday = line;

					getline(textFile, line); // space
					size++;
				}
				else
					textFile.close();
			}
		}
	}
}

void List::insert() {
	if (isFull()) {
		cout << "    List is Full!" << endl;
	}
	else {
		string line;
		cin.ignore();

		cursor = isEmpty() ? 0 : size; // setting cursor location

		cout << "    Add an entry:" << endl;
		cout << "    Name: ";
		getline(cin, line);
		personData[cursor].name = line;

		cout << "    Phone: ";
		getline(cin, line);
		personData[cursor].phoneNum = line;

		cout << "    Birthday: ";
		getline(cin, line);
		personData[cursor].birthday = line;

		size++;
	}
}

void List::remove() {
	if (isEmpty()) {
		cout << "    List is Empty!" << endl;
	}
	else {
		bool noMatching = 1;
		string line;

		cin.ignore();
		cout << "    Remove an entry:" << endl;
		cout << "    Name: ";
		getline(cin, line);

		for (int i = 0; i < size; i++) {
			if (personData[i].name == line) {
				noMatching = 0;
				if (i == size - 1) { // for the case that cursor is at the end
					personData[i].name = "";
					personData[i].phoneNum = "";
					personData[i].birthday = "";
					cursor = 0;
				}
				else {
					for (int j = i; j < size - 1; j++) {
						personData[j].name = personData[j + 1].name;
						personData[j + 1].name = "";
						personData[j].phoneNum = personData[j + 1].phoneNum;
						personData[j + 1].phoneNum = "";
						personData[j].birthday = personData[j + 1].birthday;
						personData[j + 1].birthday = "";
					}
					cursor = i;
				}
				size--;
				break;
			}
		}
		if (noMatching) cout << "    " + line + " is NOT exist in the list" << endl;
	}
}

void List::write() {
	string fileName;

	cin.ignore();
	cout << "    Enter the name of the file: ";
	getline(cin, fileName);

	ofstream textFile(fileName + ".txt");
	if (textFile.is_open()) {
		for (int i = 0; i < size; i++) {
			textFile << personData[i].name << endl;
			textFile << personData[i].phoneNum << endl;
			textFile << personData[i].birthday << endl << endl;
		}
		textFile.close();
		cout << "    The list is written into " << fileName << endl << endl;
	}
	else {
		cout << "    Unable to open " + fileName << endl << endl;
	}
}

void List::showInfo() {
	int jan(0), feb(0), mar(0), apr(0), may(0), jun(0), jul(0), aug(0), sep(0), oct(0), nov(0), dec(0);
	
	cout << "    Total number of entries in the list: " << size << endl;
	cout << "    Number of birthdays in" << endl;

	for (int i = 0; i < size; i++) {
		string month = personData[i].birthday.substr(0, 2);
		int mon = stoi(month);
		switch (mon) {
		case 1: jan++; break;
		case 2: feb++; break;
		case 3: mar++; break;
		case 4: apr++; break;
		case 5: may++; break;
		case 6: jun++; break;
		case 7: jul++; break;
		case 8: aug++; break;
		case 9: sep++; break;
		case 10: oct++; break;
		case 11: nov++; break;
		case 12: dec++; break;
		}
	}

	if (jan) cout << "\t" << "January:" << jan << endl;
	if (feb) cout << "\t" << "February:" << feb << endl;
	if (mar) cout << "\t" << "March:" << mar << endl;
	if (apr) cout << "\t" << "April:" << apr << endl;
	if (may) cout << "\t" << "May:" << may << endl;
	if (jun) cout << "\t" << "June:" << jun << endl;
	if (jul) cout << "\t" << "July:" << jul << endl;
	if (aug) cout << "\t" << "August:" << aug << endl;
	if (sep) cout << "\t" << "September:" << sep << endl;
	if (oct) cout << "\t" << "October:" << oct << endl;
	if (nov) cout << "\t" << "November:" << nov << endl;
	if (dec) cout << "\t" << "December:" << dec << endl;

	cout << endl;
}

void List::showInfoByMonth() {
	bool noMatching = 1;
	int count = 0;
	string line;

	cin.ignore();
	cout << "    Enter the selected month: ";
	getline(cin, line);

	for (int i = 0; i < size; i++) {
		if (line == birthdayString(personData[i]))
			count++;
	}

	cout << "    Total number of birthdays in " << line << ": " << count << endl;
	for (int i = 0; i < size; i++) {
		if (line == birthdayString(personData[i])) {
			noMatching = 0;
			cout << "\t" << personData[i].name << endl;
			cout << "\t" << personData[i].phoneNum << endl;
			cout << "\t" << personData[i].birthday << endl << endl;
		}
	}
	if (noMatching) cout << endl;
}

string List::birthdayString(Person& person) {
	string month = person.birthday.substr(0, 2);
	int mon = stoi(month);

	switch (mon) {
	case 1: month = "January"; break;
	case 2: month = "February"; break;
	case 3: month = "March"; break;
	case 4: month = "April"; break;
	case 5: month = "May"; break;
	case 6: month = "June"; break;
	case 7: month = "July"; break;
	case 8: month = "August"; break;
	case 9: month = "September"; break;
	case 10: month = "October"; break;
	case 11: month = "November"; break;
	case 12: month = "December"; break;
	}
	return month;
}

void List::clear() {
	for (int i = 0; i < size; i++) {
		personData[i].name = "";
		personData[i].phoneNum = "";
		personData[i].birthday = "";
	}
	size = 0;
	cursor = -1;
}

bool List::isEmpty() const {
	return size == 0;
}

bool List::isFull() const {
	return size == maxSize;
}