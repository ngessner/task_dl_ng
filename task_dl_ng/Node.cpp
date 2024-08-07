#include "Node.h"

Node* Node::getNext()
{
	return next;
}
Node* Node::getPrev()
{
	return prev;
}

Task* Node::getTask()
{
	return task;
}

void Node::setNext(Node* desiredNext)
{
	next = desiredNext;
}
void Node::setPrev(Node* desiredPrev)
{
	prev = desiredPrev;
}
void Node::setTask(Task* desiredTask)
{
	task = desiredTask;
}