// CSE2017-01 Data Structure
// Project2
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 May 12
//
// listlnk.h
// :Class declarations for the linked list implementation of the List ADT


template < class DT >
class List;

template < class DT >
class Person {
private:
	// Constructor
	Person(const DT& nameData, Person* nextPtr);

	// Data members
	DT name;
	Person* next;
	List<DT>* friendList;

	friend class  List<DT>;
};

//--------------------------------------------------------------------

template<class DT>
class List
{
public:
	// Constructor
	List(int ignored = 0);

	// Destructor
	~List();

	// List manipulation operations
	void insert(const DT& newData);
	void remove();
	void clear();

	// List status operations
	bool isEmpty() const;
	bool isFull() const;

	// List iteration operations
	void gotoBeginning();
	bool gotoNext();
	bool gotoPrior();

	// Output the list structure - used in testing/debugging
	void showStructure() const;

	// project2 operations
	bool isExist_setCur(const DT& p);
	void isFriend(const DT& p1, const DT& p2);
	void friends(const DT& p1, const DT& p2);
	void unfriends(const DT& p1, const DT& p2);
	void printFriendList(const DT& p);
	
private:
	Person<DT>* head, * cursor;
};