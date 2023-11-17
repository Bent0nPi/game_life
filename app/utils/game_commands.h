#ifndef GAME_COMMANDS_HEADER
#define GAME_COMMANDS_HEADER
#include <iostream>

// GameCommand enum used for tagging comands internal program
enum GameCommand {
  TICK = 1,
  INITIALIZE,
  DUMP,
  STATISTICS,
  HELP_COMMAND,
  HELP_LIST,
  EXIT
};

#endif
