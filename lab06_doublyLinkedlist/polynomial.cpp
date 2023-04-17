// CSE2017-01 Data Structure
// Lab 06 - Doubly Linked List
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 April 15
//
// polynomial.cpp
// :Polynomial program that using doubly liked list

#include <iostream>
#include <cmath>
#include <string>
#include "listdbl.cpp"

using namespace std;

class Poly {
private:
	int degree;
	int coefficient;

public:
	Poly() :degree(0), coefficient(0) {}
	Poly(int c, int d) :coefficient(c), degree(d) {}
	int getCoef() { return coefficient; }
	int getDegree() { return degree; }
};

template<class DT>
bool List<DT>::hasNext() {
	return (cursor->next);
}

void add(List<Poly>* list, int c, int d) {
	if (list->isEmpty()) {
		if (c < 0) { // when the first element is negative
			Poly newNode(-c, d);
			list->insert(newNode);
		}
		else {
			Poly newNode(c, d);
			list->insert(newNode);
		}
	}
	else {
		Poly newNode(c, d);
		list->gotoBeginning();
		while (1) {
			if (list->getCursor().getDegree() < d) {
				Poly newNode2(list->getCursor().getCoef(), list->getCursor().getDegree());
				list->insert(newNode);
				list->gotoPrior();
				list->remove();
				list->insert(newNode2);
				break;
			}
			else if (list->getCursor().getDegree() == d) {
				int cc = list->getCursor().getCoef() + c;
				Poly newNode2(cc, d);
				list->replace(newNode2);
				break;
			}
			else {
				if (!list->hasNext()) {
					list->insert(newNode);
					break;
				}
				list->gotoNext();
			}
		}
		if (list->getCursor().getCoef() == 0)
			list->remove();
	}
}

void showPolynomial(List<Poly>& list) {
	if (list.isEmpty()) {
		cout << "Empty Polynomial" << endl;
	}
	else {
		list.gotoBeginning();

		if (list.getCursor().getDegree() == 0) {
			cout << list.getCursor().getCoef();
		}
		else if (list.getCursor().getCoef() == 1) {
			cout << "x^" << list.getCursor().getDegree();
		}
		else if (list.getCursor().getCoef() == -1) {
			cout << "-x^" << list.getCursor().getDegree();
		}
		else {
			cout << list.getCursor().getCoef() << "x^" << list.getCursor().getDegree();
		}

		while (list.gotoNext()) {
			if (list.getCursor().getDegree() == 0) {
				cout << " + " << list.getCursor().getCoef();
			}
			else if (list.getCursor().getCoef() == 1) {
				cout << " + x^" << list.getCursor().getDegree();
			}
			else if (list.getCursor().getCoef() == -1) {
				cout << " - x^" << list.getCursor().getDegree();
			}
			else if (list.getCursor().getCoef() < 0) {
				cout << " - " << -(list.getCursor().getCoef()) << "x^" << list.getCursor().getDegree();
			}
			else {
				cout << " + " << list.getCursor().getCoef() << "x^" << list.getCursor().getDegree();
			}
		}
		cout << endl;
	}
}


void main() {
	List<Poly> testList;   // Test list
	string testData;
	int co, de;          // List data item
	char cmd;                  // Input command

	do {
		showPolynomial(testList);                     // Output list

		cout << endl << "Command(sign degree coefficient): ";                  // Read command
		cin >> cmd;

		switch (cmd) {
		case '+':   // plus
			getline(cin, testData);
			de = stoi(testData.substr(0, 1));
			co = stoi(testData.substr(2, 1));
			if (co != 0) {
				add(&testList, co, de);
			}

			break;

		case '-':                                  // minus
			getline(cin, testData);
			de = stoi(testData.substr(0, 1));
			co = -1 * stoi(testData.substr(2, 1));
			if (co != 0) {
				add(&testList, co, de);
			}
			break;

		case 'C': case 'c':                       // clear
			testList.clear();
			break;

		case 'Q': case 'q':                   // Quit test program
			break;

		default:                               // Invalid command
			cout << "Inactive or invalid command" << endl;
		}
	} while (cmd != 'Q' && cmd != 'q');
}