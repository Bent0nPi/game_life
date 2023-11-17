#include "iterator.h"
#include "../game_space_classes/universe.h"
#include <exception>
#include <iostream>
#include <stdexcept>

Iterator::Iterator(Field *currentState, Field *nextState,
                   Universe *gameUniverse) {
  currentState_ = currentState;
  nextState_ = nextState;
  gameUniverse_ = gameUniverse;
}

// getNextIteration function once uses rules to field
void Iterator::getNextIteration() {
  // make nextState_ field's sizes and field's sizes same
  (*nextState_) = (*currentState_);
  int fieldHeight = currentState_->getHeight();
  int fieldWidth = currentState_->getWidth();
  set<int> birthRule = gameUniverse_->getBirthRule();
  set<int> surviveRule = gameUniverse_->getSurviveRule();

  // count neighbours
  for (int i = 0; i < fieldHeight; i++) {
    for (int j = 0; j < fieldWidth; j++) {
      int countNeighbours = 0;
      for (int k = -1; k < 2; k++) {
        for (int l = -1; l < 2; l++) {
          countNeighbours +=
              currentState_->at((fieldHeight + i + k) % fieldHeight,
                                (fieldWidth + j + l) % fieldWidth);
        }
      }
      countNeighbours -= currentState_->at(i, j); // cell counted itself
      // use rules
      if (currentState_->at(i, j) == 1) {
        if (surviveRule.find(countNeighbours) == surviveRule.end()) {
          nextState_->at(i, j) = 0;
        } else {
          nextState_->at(i, j) = 1;
        }
      } else {
        if (birthRule.find(countNeighbours) == birthRule.end()) {
          nextState_->at(i, j) = 0;
        } else {
          nextState_->at(i, j) = 1;
        }
      }
    }
  }
  // update main field
  (*currentState_) = (*nextState_);
}

// uses getNextIteration function n times
void Iterator::goOnNTicks(int countTicks) {
  for (int i = 0; i < countTicks; i++) {
    getNextIteration();
  }
}