#ifndef HELPER_HEADER
#define HELPER_HEADER
#include "../console_process_classes/i_output_compiler.h"
#include "../utils/game_commands.h"
#include "../utils/suggestions.h"
#include <iostream>
using namespace std;

// Helper class give a suggestions about commands
class Helper {
public:
  void getInfoAboutCommand(IOutputCompiler *compiler,
                           GameCommand difficultCommand);
};

#endif