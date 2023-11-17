#include "console_output_compiler.h"
#include <exception>
#include <iostream>

// printInfo function shows infoabout universe and current stage of field
void ConsoleCompiler::printInfo(string gameName, char **field, int height,
                                int width, set<int> birthRule,
                                set<int> surviveRule) {
  cout << "Universe: " << gameName << endl;
  cout << "Birth rule: ";
  for (set<int>::iterator it = birthRule.begin(); it != birthRule.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "Survival rule: ";
  for (set<int>::iterator it = surviveRule.begin(); it != surviveRule.end();
       it++) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "Current state: " << endl;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << (int)(field[i][j]) << " ";
    }
    cout << endl;
  }
}

// printRequest shows request for new command
void ConsoleCompiler::printRequest() {
  cout << "Please, print next command" << endl;
}

// printError shows message of exception
void ConsoleCompiler::printError(GameLogicException &gameException) {
  cout << gameException.what() << endl;
}

// printHelp shows message of suggestion
void ConsoleCompiler::printHelp(ICommandSuggestion &hint) {
  cout << hint.what() << endl;
}