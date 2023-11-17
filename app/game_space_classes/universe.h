#ifndef UNIVERSE_HEADER
#define UNIVERSE_HEADER
#include <iostream>
#include <set>

using namespace std;

// class Universe contains name of game and rule for bitrh and survival
class Universe {
private:
  string name_;
  set<int> birthRule_;
  set<int> surviveRule_;

public:
  Universe();
  void setName(string universeName);
  string getName();
  void setBirthRule(set<int> newBirthRule);
  set<int> getBirthRule();
  void setSurviveRule(set<int> newSurviveRule);
  set<int> getSurviveRule();
};

#endif