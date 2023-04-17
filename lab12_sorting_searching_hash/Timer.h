// CSE2017-01 Data Structure
// Lab 12 - Sorting, Searching, Hash
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 June 2
//
// Timer.h
// :Class declaration for the Timer ADT


// Insert a declaration for SystemTime here.
#include <ctime>

typedef clock_t SystemTime;

class Timer
{
public:

    // Start and stop the timer
    void start();
    void stop();

    // Compute the elapsed time (in seconds)
    double getElapsedTime() const;

private:

    SystemTime startTime,   // Time that the timer was started
        stopTime;    // Time that the timer was stopped
};
