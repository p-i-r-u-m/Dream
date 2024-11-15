// task-display-CLI.cpp

// Connect libraries
#include <iostream>
#include <vector>
#include <string>

// Connect header files
#include "./include/task-display-CLI.h"

void displayTasks(const std::vector<Task>& tasks) {
  for (const auto& task : tasks) {
    std::cout << "Task: " << task.name << "\n"
      << "Priority: " << task.priority << "\n"
      << "Due date: " << task.due_date << "\n\n";
  }
}

