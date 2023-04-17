// CSE2017-01 Data Structure
// Lab 05 - queue
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 April 9
//
// queueArr.h
// :Class declaration for the array implementation of the Queue ADT


const int defMaxQueueSize = 10;   // Default maximum queue size

template < class DT >
class Queue
{
public:
    // Constructor
    Queue(int maxNumber = defMaxQueueSize);

    // Destructor
    ~Queue();

    // Queue manipulation operations
    void enqueue(const DT& newData);        // Enqueue data element
    DT dequeue();                             // Dequeue data element

    void clear();                            // Clear queue

    // Queue status operations
    bool isEmpty() const;                    // Queue is empty
    bool isFull() const;                     // Queue is full

    // Output the queue structure -- used in testing/debugging
    void showStructure() const;

    void putFront(const DT& newDataItem); //Lab 2
    DT getRear(); //Lab 2
    int getLength() const; //Lab 3

private:

	// Data members
	int maxSize,   // Maximum number of elements in the queue
		front,     // Index of the front element
		rear;      // Index of the rear element
	DT* element;   // Array containing the queue elements
};