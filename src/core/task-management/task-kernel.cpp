// task-kernel.cpp

// Connect libraries
#include <iostream>
#include <vector>
#include <string>

// Connect header files
#include "./include/task.h"
#include "./include/task-creation.h"
#include "./include/task-display-CLI.h"

int main (int argc, char *argv[]) {

  std::vector<Task> tasks;
  addTask(tasks, "Complete project", "H", "2024-11-20");
  addTask(tasks, "Buy groceries", "L", "2024-11-18");

  displayTasks(tasks);

  return 0;
}
