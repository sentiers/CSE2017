// CSE2017-01 Data Structure
// Project1 - List(Array)
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 April 15
//
// listarr.h
// :Class declaration for the array implementation of the List ADT


#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int defMaxListSize = 20;

typedef struct Person{
	string name;
	string phoneNum;
	string birthday;
} Person;

class List {
public:
	List(int maxNumber = defMaxListSize);
	~List();

	void read(); // read file
	void insert(); // insert person
	void remove(); // remove data by name
	void write(); // write file

	void showInfo(); // display list information
	void showInfoByMonth(); // display people by birthday month

	string birthdayString(Person& person); // return bithday month

	void clear(); // clear
	bool isEmpty() const; // check if it is empty
	bool isFull() const; // check if it is full					 

private:
	int maxSize,
		size,
		cursor;

	Person* personData;
};