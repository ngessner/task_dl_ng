#pragma once
#include "Node.h"
#include <fstream>

class TaskList
{
	private:
		Node* head = nullptr;
		Node* tail = nullptr;
	public:
		void addTask(Task* task);		
		void insertTaskAfter(int, Task*);
		void removeTask(int);

		void readFile();
		void writeToFile();

		void displayForward();
		void displayBackward();
};

