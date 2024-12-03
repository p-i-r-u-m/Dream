#ifndef TASK_DATABASE_H
#define TASK_DATABASE_H

#include <sqlite3.h>
#include <string>

// Initialize the database
void saveTaskToDatabase(const std::string database, const int task_id,
    const std::string task_name, const int task_priority,
    const int task_status);

#endif // TASK_DATABASE_H
