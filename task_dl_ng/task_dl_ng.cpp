#include "TaskList.h"

int main()
{
    TaskList taskDl;

    taskDl.readFile();

    //taskDl.addTask(new Task(1, "birthday", "10-29-2024"));
    //taskDl.addTask(new Task(2, "second birthday", "10-29-2025"));
    //taskDl.addTask(new Task(3, "third birthday", "10-29-2026"));
    //taskDl.insertTaskAfter(1, new Task(9999, "INSERTED", "10-29-2027"));
    //taskDl.addTask(new Task(4, "idk", "10-2999-2026"));
    //taskDl.removeTask(9999);

    taskDl.displayForward();
    taskDl.displayBackward();

  /*taskDl.writeToFile();*/    
}
