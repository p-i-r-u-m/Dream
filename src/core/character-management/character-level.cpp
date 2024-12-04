// character-level.cpp

// Connect libraries
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// Connect headers
#include "./include/character.h"
#include "./include/character-level.h"
#include "./include/character-database.h"

std::vector<Character> HeroStatsLevel;

void IncreaseProficiency(const std::string database,
    const int points)
{
  HeroStatsLevel = {};
  
  // Open database in read mode
  std::ifstream CharacterDatabase(database);

  // Check if file is open
  if (!CharacterDatabase.is_open()) {
    std::cerr << "Error: Unable to open or create database file!" << std::endl;
    return;
  }

  // std::cout << "File opened successfully!" << std::endl;

  char c;
  bool dataFound = false;

  std::string line;
  Character stat;  

  // Reading database line by line
  while (std::getline(CharacterDatabase, line)) {
    std::istringstream stream(line);

    // Reading every line of file
    stream >> stat.level >> stat.proficiency >> stat.upLevel;

    std::getline(stream >> std::ws, stat.name);

    // Debugging
    // std::cout << stat.level << stat.proficiency << stat.upLevel << stat.name;

  }

  // Add points to proficiency
  stat.proficiency += points;

  HeroStatsLevel.push_back(stat);

  saveStatsToDatabase(database, HeroStatsLevel, false);
  
  std::cout << "\033[1;32m\n\nProficiency +" << points
    << "\033[0m\033[1m\n   Each step forward is a victory, a testament to your growth.\n   Keep pushing, for the path you forge now shapes the greatness you'll achieve tomorrow.\033[0m\n\n";
  
  HeroLevelManagement(database);

  // Close file
  CharacterDatabase.close();
  

}

void HeroLevelManagement(const std::string database) {
  HeroStatsLevel = {};

  // Open database in read mode
  std::ifstream CharacterDatabase(database);

  // Check if file is open
  if (!CharacterDatabase.is_open()) {
    std::cerr << "Error: Unable to open or create database file!" << std::endl;
    return;
  }

  // std::cout << "File opened successfully!" << std::endl;

  char c;
  bool dataFound = false;

  std::string line;
  Character stat;  

  // Reading database line by line
  while (std::getline(CharacterDatabase, line)) {
    std::istringstream stream(line);

    // Reading every line of file
    stream >> stat.level >> stat.proficiency >> stat.upLevel;

    std::getline(stream >> std::ws, stat.name);

    // Debugging
    // std::cout << stat.level << stat.proficiency << stat.upLevel << stat.name;

  }

  if (stat.proficiency >= stat.upLevel) {
    stat.level += 1;
    stat.proficiency -= stat.upLevel;
    stat.upLevel += 15;
    
    HeroStatsLevel.push_back(stat);
    saveStatsToDatabase(database, HeroStatsLevel, false);
    
    std::cout << "\033[1;35m\n\nLEVEL +1\n\033[0m\033[1m   Well done, keep going!\033[0m\n\n";
  }

  // Close file
  CharacterDatabase.close();
  
} 
  
