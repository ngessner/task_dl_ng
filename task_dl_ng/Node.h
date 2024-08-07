#pragma once
#include "Task.h"

class Node
{
	private:
		Node* next;
		Node* prev;
		Task* task;

	public:	
		Node* getNext();
		Node* getPrev();
		Task* getTask();

		void setNext(Node*);
		void setPrev(Node*);
		void setTask(Task*);
};

