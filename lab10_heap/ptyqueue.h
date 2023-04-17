// CSE2017-01 Data Structure
// Lab 10 - Heap - inlab1
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 May 21
//
// ptyqueue.h
// :Class declaration for the heap implementation of the Priority Queue ADT
//  - inherits the array implementation of the Heap ADT


#include "heap.cpp"

const int defMaxQueueSize = 10;   // Default maximum queue size

template < class DT >
class PtyQueue : public Heap<DT>
{
  public:

    // Constructor
    PtyQueue ( int maxNumber = defMaxQueueSize );

    // Queue manipulation operations
    void enqueue ( const DT &newDataItem );   // Enqueue data element
    DT dequeue ();                            // Dequeue data element
};
