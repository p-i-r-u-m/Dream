#ifndef TASK_DATABASE_H
#define TASK_DATABASE_H

#include <sqlite3.h>
#include <string>

// Initialize the database
void saveTaskToDatabase(const std::string database, const int task_id,
    const std::string task_name, const std:: string task_priority);

#endif // TASK_DATABASE_H
