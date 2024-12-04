// character-database.h
#ifndef CHARACTER_DATABASE_H
#define CHARACTER_DATABASE_H

#include "character.h"
#include <string>

// Initialize the database
void saveStatsToDatabase(const std::string database, const std::vector<Character> HeroStats,
    const bool CLI);

#endif // CHARACTER_DATABASE_H
