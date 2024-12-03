#ifndef TASK_DATABASE_H
#define TASK_DATABASE_H

#include "task.h"
#include <string>

// Initialize the database
void saveTaskToDatabase(const std::string database, const int task_id,
    const std::string task_name, const int task_priority,
    const int task_status, const bool CLI);

void deleteTaskFromDatabase(const std::string& database, int taskIndex);

void checkDoneTaskFromDatabase(const std::string& database, const int taskID);

#endif // TASK_DATABASE_H
