// CSE2017-01 Data Structure
// Lab 12 - Sorting, Searching, Hash
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 June 2
//
// hashtbl.cpp
// :Implementation of the Hash Table ADT


#include <iostream>
#include "hashtbl.h"

template < class DT, class KF >
HashTbl<DT, KF>::HashTbl(int initTableSize) : tableSize(initTableSize) {
	dataTable = new List<DT>[tableSize];
}

template < class DT, class KF >
HashTbl<DT, KF>::~HashTbl() {
	clear();
}

template < class DT, class KF >
void HashTbl<DT, KF>::insert(const DT& newDataItem) {
	if (isFull()) {
		cout << "Hash Table is Full" << endl;
	}
	else {
		for (int i = 0; i < tableSize; i++) {
			if (!dataTable[i].isEmpty()) {
				dataTable[i].gotoBeginning();
				do {   //If a data item with the same key as newDataItem already exists in the list
					if (dataTable[i].getCursor().getKey() == newDataItem.getKey()) {
						dataTable[i].getCursor().setKey(newDataItem.getKey());
						return;
					}
				} while (dataTable[i].gotoNext());
			}
		}
		// newDataItem is new
		dataTable[newDataItem.hash(newDataItem.getKey()) % tableSize].insert(newDataItem);
	}
}

template < class DT, class KF >
bool HashTbl<DT, KF>::remove(KF searchKey) {
	for (int i = 0; i < tableSize; i++) {
		if (!dataTable[i].isEmpty()) {
			dataTable[i].gotoBeginning();
			do {
				if (dataTable[i].getCursor().getKey() == searchKey) {
					dataTable[i].remove();
					return true;
				}
			} while (dataTable[i].gotoNext());
		}
	}
	return false;
}

template < class DT, class KF >
bool HashTbl<DT, KF>::retrieve(KF searchKey, DT& dataItem) {
	for (int i = 0; i < tableSize; i++) {
		if (!dataTable[i].isEmpty()) {
			dataTable[i].gotoBeginning();
			do {
				if (dataTable[i].getCursor().getKey() == searchKey) {
					dataItem = dataTable[i].getCursor();
					return true;
				}
			} while (dataTable[i].gotoNext());
		}
	}
	return false;
}

template < class DT, class KF >
void HashTbl<DT, KF>::clear() {
	for (int i = 0; i < tableSize; i++) {
		dataTable[i].clear();
	}
}

template < class DT, class KF >
bool HashTbl<DT, KF>::isEmpty() const {
	if (dataTable != NULL) {
		for (int i = 0; i < tableSize; i++) {
			if (!dataTable[i].isEmpty()) {
				return false;
			}
		}
	}
	return true;
}

template < class DT, class KF >
bool HashTbl<DT, KF>::isFull() const {
	if (dataTable != NULL) {
		for (int i = 0; i < tableSize; i++) {
			if (!dataTable[i].isFull()) {
				return false;
			}
		}
	}
	return true;
}

template < class DT, class KF >
void HashTbl<DT, KF>::showStructure() const {
	for (int i = 0; i < tableSize; i++) {
		cout << i << ": ";
		if (dataTable[i].isEmpty())
			cout << "_";
		else {
			dataTable[i].gotoBeginning();
			do {
				cout << dataTable[i].getCursor().getKey() << " ";
			} while (dataTable[i].gotoNext());
		}
		cout << endl << endl;
	}
}
