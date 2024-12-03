// task-kernel.cpp

// Connect libraries
#include <iostream>
#include <vector>
#include <string>

// Connect header files
#include "./include/task.h"
#include "./include/task-creation.h"
#include "./include/task-display-CLI.h"
#include "./include/task-database.h"

int main (int argc, char *argv[]) {
  
  addTask();

  displayTasks("task-database.data", 0);

  checkDoneTaskFromDatabase("task-database.data", 4);


  displayTasks("task-database.data", 0);


  return 0;
}
