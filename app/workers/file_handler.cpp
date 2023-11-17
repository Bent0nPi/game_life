#include "file_handler.h"
#include "../utils/exceptions.h"
#include <bits/types/FILE.h>
#include <cctype>
#include <cstdio>
#include <exception>
#include <fstream>
#include <memory>
#include <sstream>
#include <string.h>
#include <string>
#include <type_traits>
#include <vector>
using namespace std;

// Help functions

// checkTitle checks attendence of #Life 1.06 on first line
void checkTitle(ifstream *inputStream) {
  string title;
  getline(*inputStream, title);
  if (title != "#Life 1.06") {
    throw GameLogicException("Configuration file has no format #Life 1.06");
  }
}

// getName checks #N string and gets universe's name
string getName(ifstream *inputStream) {
  // check tag
  int length = inputStream->tellg();
  string tag, gameName;
  (*inputStream) >> tag;
  if (tag != "#N") {
    inputStream->seekg(length);
    throw GameLogicException("The name of universe absent in configuration");
  }
  (*inputStream) >> gameName;
  return gameName;
}

// getRules checks format of linewith rules (right format is #R B<numbers in
// 0..8>/S<numbers in 0..8>)
void getRules(ifstream *inputStream, set<int> *birthRule,
              set<int> *surviveRule) {
  // check tag
  int length = inputStream->tellg();
  string tag, rule;
  (*inputStream) >> tag;
  if (tag != "#R") {
    inputStream->seekg(length);
    throw GameLogicException("The rules of universe absent in configuration");
  }
  // check birth rule
  (*inputStream) >> rule;
  int i = 0;
  if (rule[i] != 'B') {
    throw GameLogicException(
        "The rules of universe has no format #R B{x}/S{y}, where {x} and {y} "
        "are sequences of numbers in limits 0..8");
  }
  i++;

  while (i < rule.length() && rule[i] != '/') {
    if (isdigit(rule[i]) && rule[i] - '0' != 9) {
      birthRule->insert((int)(rule[i] - '0'));
    } else {
      throw GameLogicException(
          "The rules of universe has no format #R B{x}/S{y}, where {x} and {y} "
          "are sequences of numbers in limits 0..8");
    }
    i++;
  }
  if (i == rule.length()) {
    throw GameLogicException(
        "The rules of universe has no format #R B{x}/S{y}, where {x} and {y} "
        "are sequences of numbers in limits 0..8");
  }
  i++;
  // check survival rule
  if (rule[i] != 'S') {
    throw GameLogicException(
        "The rules of universe has no format #R B{x}/S{y}, where {x} and {y} "
        "are sequences of numbers in limits 0..8");
  }
  i++;
  while (i < rule.length()) {
    if (isdigit(rule[i]) && rule[i] - '0' != 9) {
      surviveRule->insert((int)(rule[i] - '0'));
    } else {
      throw GameLogicException(
          "The rules of universe has no format #R B{x}/S{y}, where {x} and {y} "
          "are sequences of numbers in limits 0..8");
    }
    i++;
  }
}
// isNumber check: is number a digit?
int isNumber(string number) {
  if (number.length() == 0)
    return 0;
  if (number[0] != '-' && !isdigit(number[0]))
    return 0;
  if (number[0] == '-' && number.length() == 1)
    return 0;
  for (int i = 1; i < number.length(); i++) {
    if (!isdigit(number[i]))
      return 0;
  }
  return 1;
}

// get and parse coordinates from string
void getAliveCellCoordinates(ifstream *inputStream, int *resultPointer) {
  string firstIndex, secondIndex;
  (*inputStream) >> firstIndex >> secondIndex;
  if (isNumber(firstIndex) && isNumber(secondIndex)) {
    resultPointer[0] = stoi(firstIndex);
    resultPointer[1] = stoi(secondIndex);
  } else {
    throw GameLogicException("Configuration file has no format #Life 1.06");
  }
}

// FileHandler class methods

// constructor
FileHandler::FileHandler(Field *gameField, Universe *gameUniverse) {
  gameField_ = gameField;
  gameUniverse_ = gameUniverse;
}

// initialize command  creates universe's name and rules, field
void FileHandler::initializeStateAndRules(string inputFile,
                                          IOutputCompiler *outputCompiler) {
  ifstream inputFileStream;
  int minimalFirstIndex = 0, minimalSecondIndex = 0, maximumFirstIndex = 0,
      maximumSecondIndex = 0;

  string gameName;
  set<int> birthRule = {};
  set<int> surviveRule = {};

  vector<shared_ptr<int[2]>> aliveCells;
  int currentPair[2] = {0, 0};
  inputFileStream.open(inputFile, fstream::in);
  if (!inputFileStream) {
    inputFileStream.close();
    GameLogicException exceptionIncorrectPath(
        "Could not open a file with this path");
    outputCompiler->printError(exceptionIncorrectPath);
    return;
  }
  // check title
  try {
    checkTitle(&inputFileStream);
  } catch (GameLogicException &exception) {
    inputFileStream.close();
    outputCompiler->printError(exception);
    return;
  }
  // get name
  try {
    gameUniverse_->setName(getName(&inputFileStream));
  } catch (GameLogicException &exception) {
    outputCompiler->printError(exception);
    gameUniverse_->setName("GameLife");
  }
  // check lenfth of file
  if (!inputFileStream) {
    inputFileStream.close();
    GameLogicException exceptionShortFile(
        "The file is too short, so it does not contain the rules of the "
        "universe");
    outputCompiler->printError(exceptionShortFile);
    return;
  }
  // get rules
  try {
    getRules(&inputFileStream, &birthRule, &surviveRule);
    gameUniverse_->Universe::setBirthRule(birthRule);
    gameUniverse_->Universe::setSurviveRule(surviveRule);
  } catch (GameLogicException &exception) {
    if (strcmp(exception.what(),
               "The rules of universe absent in configuration") != 0) {
      inputFileStream.close();
      outputCompiler->printError(exception);
      return;
    } else {
      outputCompiler->printError(exception);
    }
  }

  while (inputFileStream) {
    try {
      // check end of file
      int currentLength = inputFileStream.tellg();
      string testLine, testFirstWord = "";
      stringstream testStringStream;
      inputFileStream >> testLine;
      testStringStream << testLine;
      testStringStream >> testFirstWord;
      if (testFirstWord == "") {

        break;
      } else {
        inputFileStream.seekg(currentLength);
      }
      getAliveCellCoordinates(&inputFileStream, currentPair);

      // compare coordinates for allocation array of suitable size

      if (minimalFirstIndex > currentPair[0]) {
        minimalFirstIndex = currentPair[0];
      }
      if (minimalSecondIndex > currentPair[1]) {
        minimalSecondIndex = currentPair[1];
      }
      if (maximumFirstIndex < currentPair[0]) {
        maximumFirstIndex = currentPair[0];
      }
      if (maximumSecondIndex < currentPair[1]) {
        maximumSecondIndex = currentPair[1];
      }

      int samePairsCounter = 0;
      for (vector<shared_ptr<int[2]>>::iterator it = aliveCells.begin();
           it != aliveCells.end(); it++) {
        if ((*it)[0] == currentPair[0] && (*it)[1] == currentPair[1]) {
          GameLogicException exceptionSameCells(
              "There are the same coordinates of alive cells in file");
          outputCompiler->printError(exceptionSameCells);
          samePairsCounter++;
        }
      }
      // checks same coordinates of one alive cell and add coordinates to vector
      if (samePairsCounter == 0) {
        shared_ptr<int[2]> coords = shared_ptr<int[2]>(new int[2]);
        coords.get()[0] = currentPair[0];
        coords.get()[1] = currentPair[1];
        aliveCells.push_back(coords);
      }

      if (inputFileStream.eof()) {
        break;
      }

    } catch (GameLogicException &exception) {
      inputFileStream.close();
      outputCompiler->printError(exception);
      return;
    }
  }
  // create field
  unique_ptr<Field> initField =
      make_unique<Field>(maximumFirstIndex - minimalFirstIndex +
                             10, // 10 - запас по клеткам для движения
                         maximumSecondIndex - minimalSecondIndex + 10);
  // initialize field
  for (vector<shared_ptr<int[2]>>::iterator it = aliveCells.begin();
       it != aliveCells.end(); it++) {
    initField->at((*it)[0] - minimalFirstIndex, (*it)[1] - minimalSecondIndex) =
        1;
  }
  (*gameField_) = (*initField);

  inputFileStream.close();
}

// this function saves game to file in life 1.06 format
void FileHandler::saveStateAndRules(string outputFile,
                                    IOutputCompiler *outputCompiler) {
  ofstream outputFileStream;
  if (outputFile == "") {
    outputFile = "outputUniverse.life";
  }
  outputFileStream.open(outputFile, fstream::out);
  if (!outputFileStream) {
    outputFileStream.close();
    GameLogicException exceptionIncorrectPath(
        "Could not open a file with this path");
    outputCompiler->printError(exceptionIncorrectPath);
    return;
  }
  // save title
  outputFileStream << "#Life 1.06\n";
  // save name
  outputFileStream << "#N " << gameUniverse_->Universe::getName() << "\n";
  // save rules
  outputFileStream << "#R B";
  set<int> rule = gameUniverse_->Universe::getBirthRule();
  for (set<int>::iterator it = rule.begin(); it != rule.end(); it++) {
    outputFileStream << *it;
  }
  outputFileStream << "/S";
  rule = gameUniverse_->Universe::getSurviveRule();
  for (set<int>::iterator it = rule.begin(); it != rule.end(); it++) {
    outputFileStream << *it;
  }
  outputFileStream << "\n";
  // save coordinates of alive cells
  int fieldHeight = gameField_->getHeight();
  int fieldWidth = gameField_->getWidth();
  for (int i = 0; i < fieldHeight; i++) {
    for (int j = 0; j < fieldWidth; j++) {
      if (gameField_->at(i, j) == 1) {
        outputFileStream << i << " " << j << "\n";
      }
    }
  }

  outputFileStream.close();
}
