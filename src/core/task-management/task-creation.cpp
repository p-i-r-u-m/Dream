// task-creation.cpp

// Connect libraries
#include <iostream>
#include <vector>
#include <string>

// Connect header files
#include "./include/task-creation.h"

void addTask(std::vector<Task>& tasks, const std::string& name,
    const std::string& priority, const std::string& due_date)
{
  Task newTask;
  newTask.name = name;
  newTask.priority = priority;
  newTask.due_date = due_date;

  tasks.push_back(newTask);
}
