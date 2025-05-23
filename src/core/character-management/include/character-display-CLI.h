// character-display-CLI.h 
#ifndef CHARACTER_DISPLAY_CLI_H
#define CHARACTER_DISPLAY_CLI_H

#include <vector>
#include <string>

#include "character.h"

// Function declaration
void printHeroStats(const std::vector<Character> DisplayHeroStats, const int mode);
void displayHeroStats(const std::string database, const int mode);

#endif // CHARACTER_DISPLAY_CLI_H
