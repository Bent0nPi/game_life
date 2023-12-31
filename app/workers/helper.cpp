#include "helper.h"
#include "../utils/exceptions.h"
#include "../utils/suggestions.h"
#include <iostream>
using namespace std;
// choose command by GameCommand enum
void Helper::getInfoAboutCommand(IOutputCompiler *compiler,
                                 GameCommand difficultCommand) {
  switch (difficultCommand) {
  case GameCommand::TICK: {
    TickCommandSuggestion tickSuggestion;
    compiler->printHelp(tickSuggestion);
    break;
  }
  case GameCommand::INITIALIZE: {
    InitializeCommandSuggestion initSuggestion;
    compiler->printHelp(initSuggestion);
    break;
  }
  case GameCommand::DUMP: {
    DumpCommandSuggestion dumpSuggestion;
    compiler->printHelp(dumpSuggestion);
    break;
  }
  case GameCommand::EXIT: {
    ExitCommandSuggestion exitSuggestion;
    compiler->printHelp(exitSuggestion);
    break;
  }
  case GameCommand::HELP_COMMAND: {
    HelpCommandSuggestion helpSuggestion;
    compiler->printHelp(helpSuggestion);
    break;
  }
  case GameCommand::HELP_LIST: {
    CommandListSuggestion listOfCommands;
    compiler->printHelp(listOfCommands);
    break;
  }
  default: {
    // if nothing with this number
    throw GameLogicException("There is no command with defined name");
    break;
  }
  }
}