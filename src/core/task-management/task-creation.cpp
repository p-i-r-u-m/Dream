// task-creation.cpp

// Connect libraries
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// Connect header files
#include "./include/task-creation.h"
#include "./include/task-database.h"


int taskIDcounter() {
  int task_id = 0;

  // Open the file in read-write mode (for reading and updating the task ID).
  std::fstream TaskIDDatabase("/usr/local/bin/task-id.data", std::ios::in | std::ios::out);

  // If the file does not exist, create it and initialize the task ID to 1.
  if (!TaskIDDatabase) {
    std::ofstream createFile("/usr/local/bin/task-id.data");
    if (!createFile) {
      std::cerr << "Error: Unable to create Task ID database file!" << std::endl;
      return -1; // Return -1 to indicate an error.
    }
    createFile << 1; // Write the initial task ID (1) to the new file.
    createFile.close();
    return 1; // Return the first task ID.
  }

  // Attempt to read the last task ID from the file.
  TaskIDDatabase >> task_id;

  // If the file is empty or the read operation fails, set the task ID to 1.
  if (TaskIDDatabase.fail()) {
    task_id = 1;
  } else {
    // If a valid task ID is found, increment it by 1 for the next task.
    task_id++;
  }

  // Clear the stream state in case of any errors during reading.
  TaskIDDatabase.clear();
  TaskIDDatabase.seekp(0, std::ios::beg); // Move the file pointer to the beginning.

  // Write the updated task ID back to the file.
  TaskIDDatabase << task_id;

  // Close the file to ensure changes are saved.
  TaskIDDatabase.close();

  // Return the new task ID to the caller.
  return task_id;
}


void addTask() {
  // Get Task structure
  Task newTask;

  // Get ID for new task
  newTask.id = taskIDcounter();
  
  // Ask and get description of the task from user
  std::cout << "\033[1m" << "Enter task name: " << "\033[0m";
  std::getline(std::cin, newTask.name);
 

  // Ask priority of the task and check correct input 
  std::string priority;
  bool correct_priority = false;

  do {
    std::cout << "\033[1m" << "Enter priority (H/M/L): " << "\033[0m";
    std::getline(std::cin, priority);
  
    if (priority == "H" || priority == "h"
        || priority == "M" || priority == "m" 
        || priority == "L" || priority == "l"
        || priority.empty())
    {
      // if user input relevant option the loop of asking will end 
      correct_priority = true;
    } else {
      // on other way it will print error and ask one more time
      std::cerr << "Please enter relevant priority (H/M/L) :)" << std::endl;
      correct_priority = false;
    }

  } while(!correct_priority);

  // translate priority into number representation, for easy filtering
  if (priority == "H" || priority == "h") {
    newTask.priority = 2;
  } else if (priority == "M" || priority == "m") {
    newTask.priority = 1;
  } else {
    newTask.priority = 0;
  }


  // Set new task status to pending
  newTask.status = 0;



  saveTaskToDatabase("/usr/local/bin/task-database.data", newTask.id, newTask.name,
      newTask.priority, newTask.status, true);

}
