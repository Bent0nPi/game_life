#include "client/client.h"
#include "console_process_classes/console_input_processor.h"
#include "console_process_classes/console_output_compiler.h"
#include "console_process_classes/i_output_compiler.h"
#include "game_space_classes/field.h"
#include "game_space_classes/universe.h"
#include "utils/exceptions.h"
#include "utils/game_commands.h"
#include "utils/parse_answer_struct.h"
#include "workers/file_handler.h"
#include "workers/helper.h"
#include "workers/iterator.h"
#include "workers/statistics.h"
#include <cctype>
#include <iostream>

using namespace std;

int initializeGame(Client *gameClient, IOutputCompiler *outputMaker,
                   int argumentCount, char **arguments);

int main(int argc, char **argv) {
  // Create servers
  Field lifeField = Field();
  Universe lifeUniverse = Universe();
  Field nextStateField = lifeField;
  FileHandler gameFileHandler = FileHandler(&lifeField, &lifeUniverse);
  Iterator automatIterator =
      Iterator(&lifeField, &nextStateField, &lifeUniverse);
  Helper gameHelper = Helper();
  Statistics gameStatisticsService = Statistics(&lifeField, &lifeUniverse);
  ConsoleCompiler consoleOutputCompiler = ConsoleCompiler();
  ConsoleInputProcessor consoleInputProcessor =
      ConsoleInputProcessor(&consoleOutputCompiler);

  // create actor
  Client gameClient = Client(
      &consoleOutputCompiler, &consoleInputProcessor, &gameFileHandler,
      &gameFileHandler, &automatIterator, &gameStatisticsService, &gameHelper);

  initializeGame(&gameClient, &consoleOutputCompiler, argc, argv);

  return 0;
}

int initializeGame(Client *gameClient, IOutputCompiler *outputMaker,
                   int argumentCount, char **arguments) {
  parseAnswerStruct initCommand = {GameCommand::INITIALIZE,
                                   GameCommand::HELP_LIST, 0, ""};
  // check count of arguments
  if (argumentCount == 1) {
    // standart input file
    initCommand.filename = "example.life";
  } else if (argumentCount == 2 || argumentCount == 3 || argumentCount == 4) {
    initCommand.filename = arguments[1];
  } else {
    GameLogicException exceptionArgumentsCount(
        "There are too many arguments in function calling");
    outputMaker->printError(exceptionArgumentsCount);
    return 1;
  }
  // initialize game
  gameClient->setCommandState(initCommand);
  gameClient->execute();
  // online mode
  if (argumentCount == 1 || argumentCount == 2) {
    while (true) {
      gameClient->request();
      gameClient->execute();
    }
  } else { // offline mode
    int gameTicks = 0;
    int iter = 0;
    while (arguments[2][iter] != 0) {
      // check digit
      if (!isdigit(arguments[2][iter])) {
        GameLogicException exceptionIntArgument(
            "There should be an int type argument here");
        outputMaker->printError(exceptionIntArgument);
      } else { // convert string to int
        gameTicks = gameTicks * 10 + (int)(arguments[2][iter]);
      }
      iter++;
    }
    // iterate
    parseAnswerStruct iterateCommand = {GameCommand::TICK,
                                        GameCommand::HELP_LIST, gameTicks, ""};
    gameClient->setCommandState(iterateCommand);
    gameClient->execute();
    parseAnswerStruct saveCommand;
    // save game
    if (argumentCount == 3) {
      saveCommand = {GameCommand::DUMP, GameCommand::HELP_LIST, 0, ""};
    } else {
      saveCommand = {GameCommand::DUMP, GameCommand::HELP_LIST, 0,
                     arguments[3]};
    }
    gameClient->setCommandState(saveCommand);
    gameClient->execute();
    return 0;
  }
}