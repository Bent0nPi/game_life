#include "field.h"
#include "iterator.h"
#include "universe.h"
#include "gtest/gtest.h"
#include <iostream>

namespace {
class IteratorTest : public testing::Test {
public:
  Field field;
  Field nextField;
  Universe universe;

protected:
  void SetUp() override {
    field = Field(10, 12);

    field.at(0, 2) = 1;
    field.at(1, 0) = 1;
    field.at(1, 2) = 1;
    field.at(2, 1) = 1;
    field.at(2, 2) = 1;
    nextField = field;
    universe = Universe();
  }

  void TearDown() override {}
};
} // namespace

TEST_F(IteratorTest, get_next_iteration_test) {
  Iterator iterator(&field, &nextField, &universe);
  iterator.getNextIteration();
  Field testField = Field(10, 12);
  testField.at(0, 1) = 1;
  testField.at(1, 2) = 1;
  testField.at(1, 3) = 1;
  testField.at(2, 1) = 1;
  testField.at(2, 2) = 1;
  ASSERT_EQ(field, testField);
}

TEST_F(IteratorTest, go_on_n_ticks_test) {
  Iterator iterator(&field, &nextField, &universe);
  iterator.goOnNTicks(4);
  Field testField = Field(10, 12);
  testField.at(1, 3) = 1;
  testField.at(2, 1) = 1;
  testField.at(2, 3) = 1;
  testField.at(3, 2) = 1;
  testField.at(3, 3) = 1;
  ASSERT_EQ(field, testField);
}
