// task.h 
#ifndef TASK_H
#define TASK_H

#include <vector>
#include <string>

// Structure of Task for saving tasks
struct Task {
  int id;
  std::string name;
  std::string priority;
};

// Function declaration



void displayTasks(const std::vector<Task>& tasks);

#endif // TASK_H
