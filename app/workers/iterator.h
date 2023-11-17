#ifndef ITERATOR_HEADER
#define ITERATOR_HEADER
#include "../game_space_classes/field.h"
#include "../game_space_classes/universe.h"
#include <iostream>

// Iterator uses rules of universe and change field
class Iterator {
private:
  Field *currentState_, *nextState_;
  Universe *gameUniverse_;

public:
  void getNextIteration();
  Iterator(Field *currentState, Field *nextState, Universe *gameUniverse);
  void goOnNTicks(int countTicks);
};

#endif