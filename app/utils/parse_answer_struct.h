#ifndef PARSE_ANSWER_STRUCT_HEADER
#define PARSE_ANSWER_STRUCT_HEADER
#include "game_commands.h"
using namespace std;
// answer struct, that keep state for Client object
struct parseAnswerStruct {
  GameCommand commandType;
  GameCommand helpCommandArgument;
  int ticks;
  string filename;
};

#endif