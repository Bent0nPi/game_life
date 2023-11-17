#include "console_output_compiler.h"
#include "field.h"
#include "file_handler.h"
#include "universe.h"
#include "gtest/gtest.h"
#include <iostream>

namespace {
class FileHandlerTest : public testing::Test {
public:
  Universe universe;
  Field field;
  ConsoleCompiler consoleCompiler;

protected:
  void SetUp() override {
    universe = Universe();
    field = Field(10, 12);
    consoleCompiler = ConsoleCompiler();
  }

  void TearDown() override {}
};
} // namespace

TEST_F(FileHandlerTest, correct_file_test) {
  FileHandler fileHandler(&field, &universe);
  fileHandler.initializeStateAndRules("../game_files/example.life",
                                      &consoleCompiler);
  Field testField = Field(12, 12);
  testField.at(0, 2) = 1;
  testField.at(1, 0) = 1;
  testField.at(1, 2) = 1;
  testField.at(2, 1) = 1;
  testField.at(2, 2) = 1;
  ASSERT_EQ(field, testField);
}

TEST_F(FileHandlerTest, incorrect_life_string) {
  Field testField = Field(10, 12);
  Universe testUniverse;
  testUniverse = Universe();
  FileHandler fileHandler(&field, &universe);
  fileHandler.initializeStateAndRules("../game_files/input_test_#Life.life",
                                      &consoleCompiler);
  ASSERT_EQ(field == testField, true);
  ASSERT_EQ(universe.getName(), testUniverse.getName());
  ASSERT_EQ(universe.getBirthRule(), testUniverse.getBirthRule());
  ASSERT_EQ(universe.getSurviveRule(), testUniverse.getSurviveRule());
}

TEST_F(FileHandlerTest, incorrect_name_string) {
  universe = Universe();
  FileHandler fileHandler(&field, &universe);
  fileHandler.initializeStateAndRules("../game_files/input_test_#N.life",
                                      &consoleCompiler);
  Field testField = Field(12, 12);
  testField.at(0, 2) = 1;
  testField.at(1, 0) = 1;
  testField.at(1, 2) = 1;
  testField.at(2, 1) = 1;
  testField.at(2, 2) = 1;
  ASSERT_EQ(field, testField);
}

TEST_F(FileHandlerTest, incorrect_rule_string) {
  FileHandler fileHandler(&field, &universe);
  fileHandler.initializeStateAndRules("../game_files/input_test_#R.life",
                                      &consoleCompiler);
  Field testField = Field(12, 12);
  testField.at(0, 2) = 1;
  testField.at(1, 0) = 1;
  testField.at(1, 2) = 1;
  testField.at(2, 1) = 1;
  testField.at(2, 2) = 1;
  Universe testUniverse = Universe();
  testUniverse.setName("Glider");
  ASSERT_EQ(field == testField, true);
  ASSERT_EQ(universe.getName(), testUniverse.getName());
  ASSERT_EQ(universe.getBirthRule(), testUniverse.getBirthRule());
  ASSERT_EQ(universe.getSurviveRule(), testUniverse.getSurviveRule());
}

TEST_F(FileHandlerTest, birth_rule_absence) {
  FileHandler fileHandler(&field, &universe);
  fileHandler.initializeStateAndRules(
      "../game_files/input_test_birth_rule.life", &consoleCompiler);
  Field testField = Field(10, 12);
  Universe testUniverse = Universe();
  testUniverse.setName("Glider");
  ASSERT_EQ(field == testField, true);
  ASSERT_EQ(universe.getName(), testUniverse.getName());
  ASSERT_EQ(universe.getBirthRule(), testUniverse.getBirthRule());
  ASSERT_EQ(universe.getSurviveRule(), testUniverse.getSurviveRule());
}

TEST_F(FileHandlerTest, survival_rule_absence) {
  FileHandler fileHandler(&field, &universe);
  fileHandler.initializeStateAndRules(
      "../game_files/input_test_survive_rule.life", &consoleCompiler);
  Field testField = Field(10, 12);
  Universe testUniverse = Universe();
  testUniverse.setName("Glider");
  ASSERT_EQ(field == testField, true);
  ASSERT_EQ(universe.getName(), testUniverse.getName());
  ASSERT_EQ(universe.getBirthRule(), testUniverse.getBirthRule());
  ASSERT_EQ(universe.getSurviveRule(), testUniverse.getSurviveRule());
}

TEST_F(FileHandlerTest, double_coordinates) {
  FileHandler fileHandler(&field, &universe);
  fileHandler.initializeStateAndRules(
      "../game_files/input_test_double_coordinates.life", &consoleCompiler);
  Field testField = Field(12, 12);
  testField.at(0, 2) = 1;
  testField.at(1, 0) = 1;
  testField.at(1, 2) = 1;
  testField.at(2, 1) = 1;
  testField.at(2, 2) = 1;
  Universe testUniverse = Universe();
  testUniverse.setName("Glider");
  ASSERT_EQ(field == testField, true);
  ASSERT_EQ(universe.getName(), testUniverse.getName());
  ASSERT_EQ(universe.getBirthRule(), testUniverse.getBirthRule());
  ASSERT_EQ(universe.getSurviveRule(), testUniverse.getSurviveRule());
}

TEST_F(FileHandlerTest, incorrect_coordinates) {
  FileHandler fileHandler(&field, &universe);
  fileHandler.initializeStateAndRules(
      "../game_files/input_test_incorrect_coordinates.life", &consoleCompiler);
  Field testField = Field(10, 12);
  Universe testUniverse = Universe();
  testUniverse.setName("Glider");
  ASSERT_EQ(field == testField, true);
  ASSERT_EQ(universe.getName(), testUniverse.getName());
  ASSERT_EQ(universe.getBirthRule(), testUniverse.getBirthRule());
  ASSERT_EQ(universe.getSurviveRule(), testUniverse.getSurviveRule());
}
