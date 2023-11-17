#ifndef EXCEPTIONS_HEADER
#define EXCEPTIONS_HEADER
#include <exception>
#include <iostream>

using namespace std;

// GameLogicException class used for custom exception system

class GameLogicException : public exception {
private:
  const char *message_;

public:
  GameLogicException(const char *message) : message_(message) {}
  const char *what();
};

#endif