#include "universe.h"
#include "gtest/gtest.h"
#include <iostream>

TEST(universe_tests, universe_creation) {
  Universe v = Universe();
  set<int> size = v.getSurviveRule();
  int m = *size.begin();
  ASSERT_EQ(m, 2);
}

namespace {
class UniverseTest : public testing::Test {
public:
  Universe universe;

protected:
  void SetUp() override { universe = Universe(); }

  void TearDown() override {}
};
} // namespace

TEST_F(UniverseTest, getters_test_f) {
  set<int> stdBirthRuleSet = {3};
  set<int> stdSurviveRuleSet = {2, 3};
  ASSERT_EQ(universe.getName(), "GameLife");
  ASSERT_EQ(universe.getBirthRule(), stdBirthRuleSet);
  ASSERT_EQ(universe.getSurviveRule(), stdSurviveRuleSet);
}

TEST_F(UniverseTest, setters_test_f) {
  set<int> stdBirthRuleSet = {5};
  set<int> stdSurviveRuleSet = {5, 6};
  universe.setBirthRule(stdBirthRuleSet);
  universe.setSurviveRule(stdSurviveRuleSet);
  universe.setName("MyGame");
  ASSERT_EQ(universe.getName(), "MyGame");
  ASSERT_EQ(universe.getBirthRule(), stdBirthRuleSet);
  ASSERT_EQ(universe.getSurviveRule(), stdSurviveRuleSet);
}
