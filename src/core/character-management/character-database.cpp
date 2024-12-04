// character-database.cpp

// Connect libraries
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// Connect headers
#include "./include/character-database.h"
#include "./include/character.h"


void saveStatsToDatabase(const std::string database, const std::vector<Character> HeroStats,
    const bool CLI)
{
  

  std::string HeroName = "Pirum";
  // Clear database and fill it with actual data
  std::ofstream CharacterDatabase(database, std::ios::trunc);;

  // Check is file open
  if (!CharacterDatabase.is_open()) {
    std::cerr << "Error: Unable to open or create database file!" << std::endl;
    return;
  }

  for (const auto& stat : HeroStats) { 
    // Include character level
    CharacterDatabase << stat.level;
    CharacterDatabase << " ";

    // Include task status
    CharacterDatabase << stat.proficiency;
    CharacterDatabase << " ";

    // Include task priority 
    CharacterDatabase << stat.upLevel;
    CharacterDatabase << " ";

    // Include task description
    CharacterDatabase << HeroName;
  
    // Finish task initalization
    CharacterDatabase << "\n";
  }

  if (CLI) {
    std::cout << "\033[32m" << "Stats added successfully!\n" << "\033[0m";
  }
}


