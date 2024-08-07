#pragma once
#include <iostream>
#include <string>

using namespace std;

class Task
{
	private:
		int id;
		string date;
		string task;

	public:
		// could have my private members point to the constructors arguments,
		// but this would make the setters useless, so heres some redundant code
		Task(int id, string task, string date )
		{			
			setId(id);
			setTask(task);
			setDate(date);
		}

		int getId();
		string getDate();
		string getTask();

		void setId(int);
		void setDate(string);
		void setTask(string);
};

