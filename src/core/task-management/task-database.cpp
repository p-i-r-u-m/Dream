// task-database.cpp

// Connect libraries
#include <iostream>
#include <fstream>

// Connect headers
#include "./include/task-database.h"

void saveTaskToDatabase(const std::string database, const int task_id,
    const std::string task_name, const std:: string task_priority)
{
  
  // Open database in write/add mode
  std::fstream TaskDatabase(database, std::ios::out | std::ios::app);

  // Check is file open
  if (!TaskDatabase.is_open()) {
    std::cerr << "Error: Unable to open or create database file!" << std::endl;
    return;
  }

  // Intialize new task
  TaskDatabase.put('@');

  // Include task ID
  TaskDatabase.put('#');
  TaskDatabase << task_id;
  TaskDatabase.put('#');
  TaskDatabase << "\n";

  // Include task description
  TaskDatabase.put('~');
  TaskDatabase << task_name;
  TaskDatabase.put('~');
  TaskDatabase << "\n";

  // Include task priority 
  TaskDatabase.put('`');
  TaskDatabase << task_priority;
  TaskDatabase.put('`');
  TaskDatabase << "\n";

  // Finish task initalization
  TaskDatabase.put('@');
  TaskDatabase << "\n";

  std::cout << "\033[32m" << "Task added successfully!\n" << "\033[0m";

}

