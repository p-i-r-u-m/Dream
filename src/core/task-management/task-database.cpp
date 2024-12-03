// task-database.cpp

// Connect libraries
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// Connect headers
#include "./include/task-database.h"

void saveTaskToDatabase(const std::string database, const int task_id,
    const std::string task_name, const int task_priority, 
    const int task_status, const bool CLI)
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

  if (CLI) {
    std::cout << "\033[32m" << "Task added successfully!\n" << "\033[0m";
  }
}



void deleteTaskFromDatabase(const std::string& database, const int taskID) {
  
  std::vector<Task> neededTasks = {};
    
  // Open database in read-write mode
  std::fstream TaskDatabase(database, std::ios::in | std::ios::out);

  // Check if file is open
  if (!TaskDatabase.is_open()) {
    std::cerr << "Error: Unable to open or create database file!" << std::endl;
    return;
  }

  // std::cout << "File opened successfully!" << std::endl;

  char c;
  bool taskFound = false;

  std::string line;
    
  // Reading database line by line
  while (std::getline(TaskDatabase, line)) {
    std::istringstream stream(line);
    Task newTask;

    // Reading every line of file
    stream >> newTask.id >> newTask.status >> newTask.priority;

    std::getline(stream >> std::ws, newTask.name);
    
    // Check is task id in the database
    if (newTask.id != taskID) {
      neededTasks.push_back(newTask);
    } else if (newTask.id == taskID){
      std::cout << "\033[32mTask " << taskID << " successfully found.\033[0m\n";
      taskFound = true;
    }
  }

  TaskDatabase.close();

  // If task with giving ID doesn't exist print error message and finish programme.
  // Otherwise delete all content in current database and rewrite everything
  //                                                      without task with giving ID.
  if (!taskFound) {
    std::cout << "\033[31mTask " << taskID << " doesn't found.\n"
      << "Please input existing ID\n\033[0m";

    return;
  } else {

    std::ofstream file(database, std::ios::trunc); // Clean file
    if (file.is_open()) {
        file.close();
        // std::cout << "\033[32mDatabase file successfully cleared.\033[0m\n";
    } else {
        std::cerr << "\033[31mError: Unable to open the database file.\033[0m\n";
    }

    // Fill database just with needed tasks
    for (const auto& task : neededTasks) {
      saveTaskToDatabase("task-database.data", task.id, task.name,
        task.priority, task.status, false);
    }
    
    std::cout << "\033[32mTask " << taskID << " deleted successfully.\033[0m" << std::endl;
    return;
  }
}


void checkDoneTaskFromDatabase(const std::string& database, const int taskID) {
  
  std::vector<Task> neededTasks = {};
    
  // Open database in read-write mode
  std::fstream TaskDatabase(database, std::ios::in | std::ios::out);

  // Check if file is open
  if (!TaskDatabase.is_open()) {
    std::cerr << "Error: Unable to open or create database file!" << std::endl;
    return;
  }

  // std::cout << "File opened successfully!" << std::endl;

  char c;
  bool taskFound = false;

  std::string line;
    
  // Reading database line by line
  while (std::getline(TaskDatabase, line)) {
    std::istringstream stream(line);
    Task newTask;

    // Reading every line of file
    stream >> newTask.id >> newTask.status >> newTask.priority;

    std::getline(stream >> std::ws, newTask.name);
    
    // Check is task id in the database
    if (newTask.id != taskID) {
      neededTasks.push_back(newTask);
    } else if (newTask.id == taskID){
      std::cout << "\033[32mTask " << taskID << " successfully found.\033[0m\n";
      newTask.status = 1;
      neededTasks.push_back(newTask);
      taskFound = true;
    }
  }

  TaskDatabase.close();

  // If task with giving ID doesn't exist print error message and finish programme.
  // Otherwise delete all content in current database and rewrite everything
  //                                         with task with giving ID checked done.
  if (!taskFound) {
    std::cout << "\033[31mTask " << taskID << " doesn't found.\n"
      << "Please input existing ID\n\033[0m";

    return;
  } else {

    std::ofstream file(database, std::ios::trunc); // Clean file
    if (file.is_open()) {
        file.close();
        // std::cout << "\033[32mDatabase file successfully cleared.\033[0m\n";
    } else {
        std::cerr << "\033[31mError: Unable to open the database file.\033[0m\n";
    }

    // Fill database just with needed tasks
    for (const auto& task : neededTasks) {
      saveTaskToDatabase("task-database.data", task.id, task.name,
        task.priority, task.status, false);
    }
    
    std::cout << "\033[32mTask " << taskID << " checked DONE.\033[0m" << std::endl;
    return;
  }
}
