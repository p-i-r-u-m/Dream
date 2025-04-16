// task.h 
#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


#include "./task-database.h"

// Structure of Task for saving tasks
struct Task { 
  int id;
  int status;
  int priority;
  std::string name;
};

// Function declaration


#endif // TASK_H
