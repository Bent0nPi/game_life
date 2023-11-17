#include "universe.h"
#include <iostream>
#include <string>

using namespace std;

Universe::Universe() {
  // standart of birth and survival rules is {3}/{2,3}
  name_ = "GameLife";
  birthRule_ = {3};
  surviveRule_ = {2, 3};
}

// getters and setters
void Universe::setName(string universeName) { name_ = universeName; }

string Universe::getName() { return name_; }

void Universe::setBirthRule(set<int> newBirthRule) {
  birthRule_ = newBirthRule;
}

set<int> Universe::getBirthRule() { return birthRule_; }

void Universe::setSurviveRule(set<int> newSurviveRule) {
  surviveRule_ = newSurviveRule;
}

set<int> Universe::getSurviveRule() { return surviveRule_; }
