// CSE2017-01 Data Structure
// Lab 03 - Stack(Array)
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 March 28
//
// palindrome2.cpp
// :palindrome check program using Stack ADT + challenge


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

	int index = -1; // when the string is already palindrome
	char c;
	for (int i = 0; i < word.size(); i++) {
		if (wordstack.isEmpty()) { 
			index = i;
			break;
		}
		c = wordstack.pop();
		if (word[i] != c) {
			if (word[i + 1] == c) 
				index = i++;
			else
				i--;
		}
	}

	cout << "index " << index << " needs to be removed to make a palindrome." << endl;
	_getch();
}