// CSE2017-01 Data Structure
// Lab 10 - Heap - inlab1
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 May 21
//
// ptyqueue.cpp
// :Heap implementation of the Priority Queue ADT


#include "ptyqueue.h"

template <class DT>
PtyQueue<DT>::PtyQueue(int maxNumber) : Heap<DT>::Heap(maxNumber) {
}

template<class DT>
void PtyQueue<DT>::enqueue(const DT& newDataItem) {
	Heap<DT>::insert(newDataItem);
}

template<class DT>
DT PtyQueue<DT>::dequeue() {
	return Heap<DT>::removeMax();
}
