// CSE2017-01 Data Structure
// Lab 10 - Heap - inlab1
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 May 21
//
// ossim.cpp
// :(Shell) Operating system task scheduling simulation
//  - Simulates an operating system's use of a priority queue to regulate access to a system resource (printer, disk, etc.).


#include <iostream>
#include <cstdlib>
#include "ptyqueue.cpp"

using namespace std;

//--------------------------------------------------------------------
//
// Declaration for the task data struct
//

struct TaskData
{
	int priority,              // Task's priority
		arrived;               // Time when task was enqueued

	void setPty(int newPty)
	{
		priority = newPty;
	}   // Set the priority

	int pty() const
	{
		return priority;
	}   // Returns the priority
};

//--------------------------------------------------------------------

void main() {

	PtyQueue<TaskData> taskPQ;   // Priority queue of tasks
	TaskData task;               // Task
	int simLength,               // Length of simulation (minutes)
		minute,                  // Current minute
		numPtyLevels,            // Number of priority levels
		numArrivals;             // Number of new tasks arriving

	cout << endl << "Enter the number of priority levels : ";
	cin >> numPtyLevels;

	cout << "Enter the length of time to run the simulator : ";
	cin >> simLength;

	//--------------------------------------------------------------------

	srand(500);
	int wait_zero = 0;
	int wait_one = 0;

	for (minute = 0; minute < simLength; minute++) {
		cout << endl << "Current minute = " << minute << endl;

		if (!taskPQ.isEmpty()) {
			task = taskPQ.dequeue();
			cout << "Task Dequeued" << endl;
			cout << "This task's priority: " << task.priority << endl;
			cout << "This task was arrived at " << task.arrived
				<< ", and waited for " << (minute - task.arrived) << " minutes." << endl;

			if ((task.priority == 0) && (minute - task.arrived > wait_zero))
				wait_zero = minute - task.arrived;
			if ((task.priority == 1) && (minute - task.arrived > wait_one))
				wait_one = minute - task.arrived;
		}

		numArrivals = rand() % 4; // instead of integer k

		if (numArrivals == 1 || numArrivals == 2) {
			cout << "Adding " << numArrivals << " task" << endl << endl;
			while (numArrivals > 0) {
				task.priority = rand() % numPtyLevels;
				task.arrived = minute;
				taskPQ.enqueue(task);
				numArrivals--;
			}
		}
		else {
			cout << "No task was added this time" << endl;
		}

		taskPQ.showStructure();
		cout << endl;
	}

	cout << "Longest wait for any low-priority(0) task: " << wait_zero << endl;
	cout << "Longest wait for any high-priority(1) task: " << wait_one << endl;

	system("pause");
}
