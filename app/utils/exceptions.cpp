#include "exceptions.h"

const char *GameLogicException::what() { return message_; }

// messages of different exceptions
/*
const char *GameNameAbsence::what() {
  return "The name of universe absents in configuration";
}

const char *FileFormatFail::what() {
  return "Configuration file has no format #Life 1.06";
}

const char *GameRuleAbsence::what() {
  return "The rules of universe absent in configuration";
}

const char *GameRuleFormatFail::what() {
  return "The rules of universe has no format #R B{x}/S{y}, where {x} and {y} "
         "are sequences of nambers in limits 0..8";
}

const char *IncorrectFilePath::what() {
  return "Could not open a file with this path";
}

const char *IncorrectCommand::what() {
  return "There is no command with defined name";
}

const char *FileExtensionFail::what() {
  return "File extension is not .life nor .lif";
}

const char *IntArgumentAbsence::what() {
  return "There should be an int type argument here";
}

const char *TooManyArguments::what() {
  return "There are too many arguments in function calling";
}

const char *TooShortFileLength::what() {
  return "The file is too short, so it does not contain the rules of the "
         "universe";
}

const char *SameAliveCells::what() {
  return "There are the same coordinates of alive cells in file";
}*/