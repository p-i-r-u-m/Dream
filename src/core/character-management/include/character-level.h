// character-level.h
#ifndef CHARACTER_LEVEL_H
#define CHARACTER_LEVEL_H

// Connect task.h because need structure of Task
#include "character.h"

void IncreaseProficiency(const std::string database,
    const int points);

void HeroLevelManagement(const std::string database); 

#endif // CHARACTER_LEVEL_H
