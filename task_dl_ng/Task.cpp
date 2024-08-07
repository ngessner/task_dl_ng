#include "Task.h"

int Task::getId()
{
	return id;
}
string Task::getDate()
{
	return date;
}
string Task::getTask()
{
	return task;
}

void Task::setId(int desiredId)
{
	id = desiredId;
}
void Task::setDate(string desiredDate)
{
	date = desiredDate;
}
void Task::setTask(string desiredTask)
{
	task = desiredTask;
}