// task-creation.h
#ifndef TASK_CREATION_H
#define TASK_CREATION_H

// Connect task.h because need structure of Task
#include "task.h"

// Function declaration
void addTask(std::vector<Task>& tasks, const std::string& name,
    const std::string& priority, const std::string& due_date);


#endif // TASK_CREATION_H
