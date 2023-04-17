// CSE2017-01 Data Structure
// Lab 12 - Sorting, Searching, Hash
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 June 2
//
// Timer.cpp
// :Implementation of the Timer ADT


#include "Timer.h"

void Timer::start()
{
	startTime = clock();
}

void Timer::stop()
{
	stopTime = clock();
}

double Timer::getElapsedTime() const
{
	return ((double)(stopTime - startTime) / (CLOCKS_PER_SEC));
}