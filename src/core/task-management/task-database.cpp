// task-database.cpp

// Connect libraries
#include <iostream>
#include <fstream>

// Connect headers
#include "./include/task-database.h"

void saveTaskToDatabase(const std::string database, const int task_id,
    const std::string task_name, const int task_priority, 
    const int task_status)
{
  
  // Open database in write/add mode
  std::fstream TaskDatabase(database, std::ios::out | std::ios::app);

  // Check is file open
  if (!TaskDatabase.is_open()) {
    std::cerr << "Error: Unable to open or create database file!" << std::endl;
    return;
  }

  // Include task ID
  TaskDatabase << task_id;
  TaskDatabase << " ";

  // Include task status
  TaskDatabase << task_status;
  TaskDatabase << " ";

  // Include task priority 
  TaskDatabase << task_priority;
  TaskDatabase << " ";

  // Include task description
  TaskDatabase << task_name;
  
  // Finish task initalization
  TaskDatabase << "\n";

  std::cout << "\033[32m" << "Task added successfully!\n" << "\033[0m";

}

