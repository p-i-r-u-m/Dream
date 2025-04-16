// main.cpp

#include <iostream>
#include <string>

#include "./core/task-management/include/task.h"
#include "./core/task-management/include/task-creation.h"
#include "./core/task-management/include/task-database.h"
#include "./core/task-management/include/task-display-CLI.h"

#include "./core/character-management/include/character.h"
#include "./core/character-management/include/character-level.h"
#include "./core/character-management/include/character-database.h"
#include "./core/character-management/include/character-display-CLI.h"

std::string task_database_path = "/usr/local/bin/task-database.data";
std::string hero_stats_database_path = "/usr/local/bin/hero-stats.data";


int main(int argc, char* argv[]) {

  if (argc == 1) {
    // if zero arguments
    displayHeroStats(hero_stats_database_path, 0);
    displayTasks(task_database_path, 0);
  } else if (argc == 2 && std::string(argv[1]) == "-t") {
    // if argument is -t
    // task
    addTask();
  } else if (argc == 3 && std::string(argv[1]) == "-dt") {
    // if argument is -dt <TASK_ID>
    // delete task
    int taskID = std::stoi(argv[2]);
    deleteTaskFromDatabase(task_database_path, taskID);
  } else if (argc == 3 && std::string(argv[1]) == "-ct") {
    // if argument is -ct <TASK_ID>
    // check task
    int taskID = std::stoi(argv[2]);
    checkDoneTaskFromDatabase(task_database_path, taskID);

  } else if (argc == 3 && std::string(argv[1]) == "-ot") {
    // if argument is -ot <DISPLAY_MODE>
    // open tasks
    int displayMode = std::stoi(argv[2]);
    displayTasks(task_database_path, displayMode);
  } else if (argc == 2 && std::string(argv[1]) == "-oh") {
    // if argument is -oh
    // open hero
    displayHeroStats(hero_stats_database_path, 0);
  } else {
    std::cerr << "Usage: " << argv[0]
      << "\n[-t] [-dt TASK_ID]\n" 
      << "[-ct TASK_ID] [-ot <DISPLAY_MODE(0,1,2)]\n"
      << "[-oh]" << std::endl;
    return 1;
  }

  return 0;
}
