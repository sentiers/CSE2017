// CSE2017-01 Data Structure
// Lab 03 - Stack(Array)
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 March 28
//
// palindrome.cpp
// :palindrome check program using Stack ADT


#include "stackarr.cpp"
#include <string>
#include <conio.h>

void main() {

	Stack<char> wordstack(100);
	string word;

	cout << "Enter a word: ";
	cin >> word;

	for (int i = 0; i < word.size(); i++) {
		wordstack.push(word[i]);
	}

	bool isPalindrome = 1;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] != wordstack.pop()) {
			isPalindrome = 0;
			break;
		}
	}

	cout << word << " is "
		<< (isPalindrome ? "" : "NOT ")
		<< "a palindrome." << endl;
	_getch();
}