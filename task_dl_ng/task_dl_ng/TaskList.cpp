#include "TaskList.h"

void TaskList::addTask(Task* newTask)
{
	Node* newNode = new Node();

	newNode->setTask(newTask);
	newNode->setNext(nullptr);
	newNode->setPrev(tail);	
	

	if (head == nullptr && tail == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->setNext(newNode);
		tail = newNode;
	}	
}

void TaskList::insertTaskAfter(int desiredId, Task* newTask)
{
	Node* currentNode = head;
	Task* currentTask = nullptr;
	int currentId = 0;

	if (newTask == nullptr)
	{	
		cout << "cannot be null";
		return;
	}	
	
	while (currentNode != nullptr)
	{
		currentTask = currentNode->getTask();
		currentId = currentTask->getId();

		if (currentId == desiredId)
		{
			break;
		}
		currentNode = currentNode->getNext();		
	}

	if (currentNode == nullptr)
	{
		cout << "id: " << desiredId << " not found";
		return;
	}

	Node* newNode = new Node();

	newNode->setTask(newTask);
	newNode->setNext(currentNode->getNext());
	newNode->setPrev(currentNode);

	if (currentNode->getNext() != nullptr)
	{
		currentNode->getNext()->setPrev(newNode);
	}

	currentNode->setNext(newNode);	
}

void TaskList::removeTask(int desiredId)
{
	Node* currentNode = head;
	Node* previousNode = nullptr;

	Task* currentTask = nullptr;
	int currentId = 0;	
	
	while (currentNode != nullptr)
	{
		currentTask = currentNode->getTask();
		currentId = currentTask->getId();

		if (currentId == desiredId)
		{
			break;
		}

		previousNode = currentNode;
		currentNode = currentNode->getNext();
	}

	if (currentNode == nullptr)
	{
		cout << "id: " << desiredId << " not found";
		return;
	}
	 
	if (currentNode == head)
	{
		head = currentNode->getNext();
	}
	else
	{
		previousNode->setNext(currentNode->getNext());
	}

	delete currentNode;
}

void TaskList::displayForward()
{
	Node* transverser = head;
	Task* task = nullptr;	

	while (transverser != nullptr)
	{
		task = transverser->getTask();

		cout << "ID: " << task->getId() << endl;
		cout << "TASK: " << task->getTask() << endl;
		cout << "DATE: " << task->getDate() << endl << endl;		

		transverser = transverser->getNext();
	}

	cout << "==============================" << endl << endl;
}

void TaskList::displayBackward()
{
	Node* transverser = tail;
	Task* task = nullptr;

	while (transverser != nullptr)
	{
		task = transverser->getTask();

		cout << "ID: " << task->getId() << endl;
		cout << "TASK: " << task->getTask() << endl;
		cout << "DATE: " << task->getDate() << endl << endl;		

		transverser = transverser->getPrev();
	}

	cout << "==============================" << endl << endl;
}

void TaskList::readFile()
{
	ifstream file("tasksData.txt");
	if (file)
	{
		int id;
		string task;
		string date;
		while (file >> id >> ws && getline(file, task, '|') && getline(file, date))
		{
			addTask(new Task(id, task, date));
		}
		file.close();
	}
	else
	{
		cout << "file not found" << endl;
	}
}

void TaskList::writeToFile()
{
	ofstream file("tasksData.txt");
	if (file)
	{
		Node* current = head;
		while (current != nullptr)
		{
			Task* task = current->getTask();
			file << task->getId() << " " << task->getTask() << "|" << task->getDate() << endl;
			current = current->getNext();
		}
		file.close();
	}
	else
	{
		cout << "file not found" << endl;
	}
}
