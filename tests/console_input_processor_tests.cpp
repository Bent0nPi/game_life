#include "console_input_processor.h"
#include "console_output_compiler.h"
#include "field.h"
#include "file_handler.h"
#include "game_commands.h"
#include "parse_answer_struct.h"
#include "universe.h"
#include "gtest/gtest.h"
#include <iostream>
#include <sstream>

namespace {
class ConsoleInputProcessorTest : public testing::Test {
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

TEST_F(ConsoleInputProcessorTest, correct_command_exit) {
  // писать exit
  ConsoleInputProcessor consoleProcessor =
      ConsoleInputProcessor(&consoleCompiler);
  parseAnswerStruct testAnswer = consoleProcessor.parseCommand();

  ASSERT_EQ(testAnswer.commandType, GameCommand::EXIT);
}

TEST_F(ConsoleInputProcessorTest, correct_command_dump_without_argument) {
  // писать dump
  ConsoleInputProcessor consoleProcessor =
      ConsoleInputProcessor(&consoleCompiler);
  parseAnswerStruct testAnswer = consoleProcessor.parseCommand();

  ASSERT_EQ(testAnswer.commandType, GameCommand::DUMP);
  ASSERT_EQ(testAnswer.filename, "");
}

TEST_F(ConsoleInputProcessorTest, correct_command_dump_with_argument) {
  // проверить dump out.life
  ConsoleInputProcessor consoleProcessor =
      ConsoleInputProcessor(&consoleCompiler);
  parseAnswerStruct testAnswer = consoleProcessor.parseCommand();

  ASSERT_EQ(testAnswer.commandType, GameCommand::DUMP);
  ASSERT_EQ(testAnswer.filename, "out.life");
}

TEST_F(ConsoleInputProcessorTest, correct_command_tick_without_argument) {
  // писать tick
  ConsoleInputProcessor consoleProcessor =
      ConsoleInputProcessor(&consoleCompiler);
  parseAnswerStruct testAnswer = consoleProcessor.parseCommand();

  ASSERT_EQ(testAnswer.commandType, GameCommand::TICK);
  ASSERT_EQ(testAnswer.ticks, 1);
}

TEST_F(ConsoleInputProcessorTest, correct_command_tick_with_argument) {
  // проверить tick 12
  ConsoleInputProcessor consoleProcessor =
      ConsoleInputProcessor(&consoleCompiler);
  parseAnswerStruct testAnswer = consoleProcessor.parseCommand();

  ASSERT_EQ(testAnswer.commandType, GameCommand::TICK);
  ASSERT_EQ(testAnswer.ticks, 3);
}

TEST_F(ConsoleInputProcessorTest, correct_command_help_without_argument) {
  // писать help
  ConsoleInputProcessor consoleProcessor =
      ConsoleInputProcessor(&consoleCompiler);
  parseAnswerStruct testAnswer = consoleProcessor.parseCommand();

  ASSERT_EQ(testAnswer.commandType, GameCommand::HELP_COMMAND);
  ASSERT_EQ(testAnswer.helpCommandArgument, GameCommand::HELP_LIST);
}

TEST_F(ConsoleInputProcessorTest, correct_command_help_with_argument) {
  // проверить help init
  ConsoleInputProcessor consoleProcessor =
      ConsoleInputProcessor(&consoleCompiler);
  parseAnswerStruct testAnswer = consoleProcessor.parseCommand();

  ASSERT_EQ(testAnswer.commandType, GameCommand::HELP_COMMAND);
  ASSERT_EQ(testAnswer.helpCommandArgument, GameCommand::INITIALIZE);
}
