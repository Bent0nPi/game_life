#include "console_input_processor.h"
#include "../utils/exceptions.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

ConsoleInputProcessor::ConsoleInputProcessor(
    IOutputCompiler *initOutputCompiler) {
  outputCompiler_ = initOutputCompiler;
}

// Function's purpose is parse command from command line and create protocol
// object (parseAnswerStruct object)
parseAnswerStruct ConsoleInputProcessor::parseCommand() {
  // so, this function works with cin
  // therefore for spliting purpose function copy line from cin to stringStream
  // commandLine = "<commandKind> <argument>".
  string consoleLine;
  getline(cin, consoleLine);
  stringstream commandLine;
  commandLine << consoleLine;
  string commandKind;
  commandLine >> commandKind;

  // check commandKind
  if (commandKind == "dump") {
    string fileName = "";
    GameLogicException exceptionFileExtension(
        "File extension is not .life nor .lif");

    // check attendence of argument
    if (commandLine >> fileName, fileName != "") {
      string fileFormatLife, fileFormatLif;
      // file can't have name shorter than 5 symbols because ".lif" - 4 symbols
      if (fileName.length() < 5) {
        outputCompiler_->printError(exceptionFileExtension);
        parseAnswerStruct errorResponse = {GameCommand::HELP_COMMAND,
                                           GameCommand::DUMP, 0, ""};
        return errorResponse;
      }
      // check formats .lif and .life
      // if file does not match these formats make FileFormatException
      fileFormatLif = fileName.substr(fileName.length() - 4, 4);
      if (fileName.length() >= 6) {
        fileFormatLife = fileName.substr(fileName.length() - 5, 5);
      }
      if (fileFormatLif != ".lif" &&
          (fileName.length() < 6 || fileFormatLife != ".life")) {
        outputCompiler_->printError(exceptionFileExtension);
        parseAnswerStruct errorResponse = {GameCommand::HELP_COMMAND,
                                           GameCommand::DUMP, 0, ""};
        return errorResponse;
      }
    }
    // create answerStruct? choose dump command and file name
    parseAnswerStruct response = {GameCommand::DUMP, GameCommand::INITIALIZE, 0,
                                  fileName};
    return response;

  } else if (commandKind == "tick") {
    // tick command have step, that equals 1 by default
    int ticks = 1;
    GameLogicException exceptionIntArgument(
        "There should be an int type argument here");
    string ticksCountString = "";

    // check unneccesary argument
    if (commandLine >> ticksCountString, ticksCountString != "") {
      int ticksCountNumber = 0;
      int dataLength = ticksCountString.length();

      // check that argument is digit
      for (int i = 0; i < dataLength; i++) {
        if (!isdigit(ticksCountString[i])) {
          outputCompiler_->printError(exceptionIntArgument);
          parseAnswerStruct errorResponse = {GameCommand::HELP_COMMAND,
                                             GameCommand::TICK, 0, ""};
          return errorResponse;
        } else {
          ticksCountNumber =
              ticksCountNumber * 10 + (ticksCountString[i] - '0');
        }
      }
      cout << ticksCountNumber << endl;
      ticks = ticksCountNumber;
    }
    // make response struct with command tick and count of ticks
    parseAnswerStruct response = {GameCommand::TICK, GameCommand::INITIALIZE,
                                  ticks, ""};
    return response;

  } else if (commandKind == "exit") {
    // make response struct with exit command
    parseAnswerStruct response = {GameCommand::EXIT, GameCommand::INITIALIZE, 0,
                                  ""};
    return response;

  } else if (commandKind == "help") {
    GameCommand commandArgument = GameCommand::HELP_LIST;
    GameLogicException exceptionIncorrectCommand(
        "There is no command with defined name");
    string argumentString = "";
    // check argument
    if (commandLine >> argumentString, argumentString != "") {
      // choose comand for help by argument
      if (argumentString == "dump") {
        commandArgument = GameCommand::DUMP;
      } else if (argumentString == "init") {
        commandArgument = GameCommand::INITIALIZE;
      } else if (argumentString == "tick") {
        commandArgument = GameCommand::TICK;
      } else if (argumentString == "exit") {
        commandArgument = GameCommand::EXIT;
      } else if (argumentString == "help") {
        commandArgument = GameCommand::HELP_COMMAND;
      } else {
        // if nothing
        outputCompiler_->printError(exceptionIncorrectCommand);
        parseAnswerStruct errorResponse = {GameCommand::HELP_COMMAND,
                                           GameCommand::HELP_LIST, 0, ""};
        return errorResponse;
      }
    }
    // make respon struct with help command and command argument
    parseAnswerStruct response = {GameCommand::HELP_COMMAND, commandArgument, 0,
                                  ""};
    return response;

  } else {
    // if have wrong kind of command put an exception
    GameLogicException exceptionIncorrectCommand =
        ("There is no command with defined name");
    outputCompiler_->printError(exceptionIncorrectCommand);
    parseAnswerStruct errorResponse = {GameCommand::HELP_COMMAND,
                                       GameCommand::HELP_LIST, 0, ""};
    return errorResponse;
  }
}
