// task.h 
#ifndef TASK_H
#define TASK_H

#include <vector>
#include <string>

// Structure of Task for saving tasks
struct Task {
  std::string name;
  std::string priority;
  std::string due_date;
};

// Function declaration
void addTask(std::vector<Task>& tasks, const std::string& name,
    const std::string& priority, const std::string& due_date);

void displayTasks(const std::vector<Task>& tasks);

#endif // TASK_H
