// character-display-CLI.cpp

// Connect libraries
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


// Connect header files
#include "./include/character.h"
#include "./include/character-database.h"
#include "./include/character-display-CLI.h"


void printHeroStats(const std::vector<Character> DisplayHeroStats, const int mode) {

  /*// Debugging*/
  /*for (const auto& stat : HeroStats)*/
  /*{*/
  /*  std::cout << stat.level << stat.proficiency << stat.upLevel << stat.name;*/
  /*}*/


  std::string avatar_part1 = R"(
 __   __               
 \ \ / /__  _   _ _ __ 
  \ V / _ \| | | | '__|
   | | (_) | |_| | |   
   |_|\___/ \__,_|_|)";
  std::string avatar_part2 = R"(                                   
     | | ___  _   _ _ __ _ __   ___ _   _ 
  _  | |/ _ \| | | | '__| '_ \ / _ \ | | |
 | |_| | (_) | |_| | |  | | | |  __/ |_| |
  \___/ \___/ \__,_|_|  |_| |_|\___|\__, |
                                    |___/ 
  )";

  std::string quote = R"(Success is not final, failure is not fatal — 
  it’s the courage to continue that defines you.)";

  if (mode == 0) {
    std::cout << "\033[1m" << avatar_part1;
    std::cout << "\033[33m" << avatar_part2 << "\033[0m\n\033[1m";
    for (const auto& stat : DisplayHeroStats) {
      std::cout 
        << "Your name:     " << stat.name << "\n\n"
        
        << "Level:         " << stat.level << "\n"
        << "Proficiency:   " << stat.proficiency << "/"
        << stat.upLevel << "\n\n";
    }
    std::cout << "\033[35m" << quote << "\033[0m\n\n";
  }
}

void displayHeroStats(const std::string database, const int mode) {
  std::vector<Character> HeroStats; 
  HeroStats = {};

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
    
  // Reading database line by line
  while (std::getline(CharacterDatabase, line)) {
    std::istringstream stream(line);
    Character stat;

    // Reading every line of file
    stream >> stat.level >> stat.proficiency >> stat.upLevel;

    std::getline(stream >> std::ws, stat.name);

    // Debugging
    // std::cout << stat.level << stat.proficiency << stat.upLevel << stat.name;

    HeroStats.push_back(stat);
  }

  // Close file
  CharacterDatabase.close();
  
  printHeroStats(HeroStats, mode);

}
