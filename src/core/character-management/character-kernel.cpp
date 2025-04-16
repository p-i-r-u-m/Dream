// character-kernel.cpp

// Connect libraries
#include <iostream>
#include <vector>
#include <string>

// Connect header files
#include "./include/character.h"
#include "./include/character-database.h"
#include "./include/character-display-CLI.h"
#include "./include/character-level.h"
#include "../task-management/include/task-display-CLI.h"

int main (int argc, char *argv[]) {
  
  Character stat;
  std::vector<Character> HeroStats;
  stat.level = 1;
  stat.proficiency = 35;
  stat.upLevel = 100;
  HeroStats.push_back(stat);


  saveStatsToDatabase("hero-stats.data", HeroStats,
    true);
  displayHeroStats("hero-stats.data", 0);

  displayTasks("task-database.data", 0);

  IncreaseProficiency("hero-stats.data", 100);

  displayHeroStats("hero-stats.data", 0);

  displayTasks("task-database.data", 0);





  return 0;
}
