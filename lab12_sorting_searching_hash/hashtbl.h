// CSE2017-01 Data Structure
// Lab 12 - Sorting, Searching, Hash
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 June 2
//
// hashtbl.h
// :Class declaration for the Hash Table ADT


#include "listlnk.cpp"

using namespace std;

template < class DT, class KF >
class HashTbl
{
public:
    HashTbl(int initTableSize);
    ~HashTbl();

    void insert(const DT& newDataItem);
    bool remove(KF searchKey);
    bool retrieve(KF searchKey, DT& dataItem);
    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

private:
    int tableSize;
    List<DT>* dataTable;
};
