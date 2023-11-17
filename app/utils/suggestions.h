#ifndef SUGGESTIONS_HEADER
#define SUGGESTIONS_HEADER
#include "i_suggestion.h"
#include <iostream>

using namespace std;

// suggestions, that help user in exploring program

class CommandListSuggestion : public ICommandSuggestion {
public:
  CommandListSuggestion() {}
  const char *what() override;
};
class TickCommandSuggestion : public ICommandSuggestion {
public:
  TickCommandSuggestion() {}
  const char *what() override;
};

class DumpCommandSuggestion : public ICommandSuggestion {
public:
  DumpCommandSuggestion() {}
  const char *what() override;
};

class ExitCommandSuggestion : public ICommandSuggestion {
public:
  ExitCommandSuggestion() {}
  const char *what() override;
};

class HelpCommandSuggestion : public ICommandSuggestion {
public:
  HelpCommandSuggestion() {}
  const char *what() override;
};

class InitializeCommandSuggestion : public ICommandSuggestion {
public:
  InitializeCommandSuggestion() {}
  const char *what() override;
};

#endif