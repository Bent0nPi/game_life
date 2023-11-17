#include "field.h"
#include "gtest/gtest.h"
#include <iostream>

namespace {
class FieldTest : public testing::Test {
public:
  Field field;

protected:
  void SetUp() override { field = Field(10, 20); }

  void TearDown() override {}
};
} // namespace

TEST_F(FieldTest, at_get_test_f) { ASSERT_EQ(field.at(0, 0), 0); }

TEST_F(FieldTest, at_set_test_f) {
  field.at(0, 0) = 1;
  ASSERT_EQ(field.at(0, 0), 1);
}

TEST_F(FieldTest, copy_constructor_test_f) {
  field.at(0, 0) = 1;
  Field nextField = field;
  ASSERT_EQ(nextField.at(0, 0), 1);
}

TEST_F(FieldTest, equating_operator_test_f) {
  Field newField = Field(2, 2);
  newField.at(1, 1) = 1;
  newField.at(0, 1) = 1;
  field = newField;
  ASSERT_EQ(field.getHeight(), 2);
  ASSERT_EQ(field.getWidth(), 2);
  ASSERT_EQ(field.at(0, 1), 1);
  ASSERT_EQ(field.at(1, 1), 1);
  ASSERT_EQ(field.at(1, 0), 0);
  ASSERT_EQ(field.at(0, 0), 0);
}