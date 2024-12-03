// task-display-CLI.cpp

// Connect libraries
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

// Connect header files
#include "./include/task-display-CLI.h"

std::vector<Task> highPriorityTasks;
std::vector<Task> mediumPriorityTasks;
std::vector<Task> lowPriorityTasks;
std::vector<Task> completedTasks;


void printTasks(const int mode)
{
  // Mode                 Action
  // ----------------------------------------
  //   0    print completed and pending tasks
  //   1    print just pending tasks
  //   2    print just completed tasks

  int count_num_tasks;

  // Print completed and pending tasks
  if (mode == 0) {
    
    std::cout << "\033[1m" << "\n======== Tasks to Do ========\n" << "\033[0m";
    
    count_num_tasks = 0;

    for (const auto& task : highPriorityTasks) {
      std::cout << "[ ] "<< "\033[31mTask " << task.id << ": " << "\033[0m"
        << task.name << std::endl;
      count_num_tasks++;
    }

    for (const auto& task : mediumPriorityTasks) {
      std::cout << "[ ] "<< "\033[33mTask " << task.id << ": " << "\033[0m"
        << task.name << std::endl;
      count_num_tasks++;
    }

    for (const auto& task : lowPriorityTasks) {
      std::cout << "[ ] "<< "\033[32mTask " << task.id << ": " << "\033[0m"
        << task.name << std::endl;
      count_num_tasks++;
    }

    std::cout << "\033[1m" << "Total: " << count_num_tasks << "\033[0m\n";

    std::cout << "\033[1m" << "\n====== Completed Tasks ======\n" << "\033[0m";
    count_num_tasks = 0;

    for (const auto& task : completedTasks) {
      std::cout << "[x] "<< "\033[34mTask " << task.id << ": " << "\033[0m"
        << task.name << std::endl;
      count_num_tasks++;
    }

    std::cout << "\033[1m" << "Total: " << count_num_tasks << "\033[0m\n";
  } 

  // Print just pending tasks
  else if (mode == 1) {

    std::cout << "\033[1m" << "\n======== Tasks to Do ========\n" << "\033[0m";
    
    int count_num_tasks = 0;

    for (const auto& task : highPriorityTasks) {
      std::cout << "[ ] "<< "\033[31mTask " << task.id << ": " << "\033[0m"
        << task.name << std::endl;
      count_num_tasks++;
    }

    for (const auto& task : mediumPriorityTasks) {
      std::cout << "[ ] "<< "\033[33mTask " << task.id << ": " << "\033[0m"
        << task.name << std::endl;
      count_num_tasks++;
    }

    for (const auto& task : lowPriorityTasks) {
      std::cout << "[ ] "<< "\033[32mTask " << task.id << ": " << "\033[0m"
        << task.name << std::endl;
      count_num_tasks++;
    }

    std::cout << "\033[1m" << "Total: " << count_num_tasks << "\033[0m\n";
  }

  // Print just completed tasks 
  else if (mode == 2) {
    
    std::cout << "\033[1m" << "\n====== Completed Tasks ======\n" << "\033[0m";
    count_num_tasks = 0;

    for (const auto& task : completedTasks) {
      std::cout << "[x] "<< "\033[34mTask " << task.id << ": " << "\033[0m"
        << task.name << std::endl;
      count_num_tasks++;
    }

    std::cout << "\033[1m" << "Total: " << count_num_tasks << "\033[0m\n";
  }
}


void displayTasks(const std::string& database, const int mode) {
  
  highPriorityTasks = {};
  mediumPriorityTasks = {};
  lowPriorityTasks = {};
  completedTasks = {};

  // Open database in read mode
  std::ifstream TaskDatabase(database);

  // Check if file is open
  if (!TaskDatabase.is_open()) {
    std::cerr << "Error: Unable to open or create database file!" << std::endl;
    return;
  }

  // std::cout << "File opened successfully!" << std::endl;

  char c;
  bool dataFound = false;

  std::string line;
    
  // Reading database line by line
  while (std::getline(TaskDatabase, line)) {
    std::istringstream stream(line);
    Task newTask;

    // Reading every line of file
    stream >> newTask.id >> newTask.status >> newTask.priority;

    std::getline(stream >> std::ws, newTask.name);

    // Додавання завдання до відповідного масиву на основі пріоритету або статусу
    if (newTask.status == 1) {
      completedTasks.push_back(newTask);
    } else {

      if (newTask.priority == 2) {
        highPriorityTasks.push_back(newTask);
      } else if (newTask.priority == 1) {
        mediumPriorityTasks.push_back(newTask);
      } else {
        lowPriorityTasks.push_back(newTask);
      }

    }
  }

  // Close file
  TaskDatabase.close();
  
  printTasks(mode);
}
