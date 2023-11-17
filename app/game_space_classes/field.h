#ifndef FIELD_HEADER
#define FIELD_HEADER
#include <bits/std_thread.h>
#include <iostream>

// classField is the class of game space.
// it contains cells and their values
// field has height and width
class Field {
private:
  char **cells_;
  int height_, width_;

public:
  Field();
  Field(int height, int width);
  Field(int height, int width, int **data);
  Field(const Field &sample);
  ~Field();
  char &at(int firstIndex, int secondIndex);
  const char &at(int firstIndex, int secondIndex) const;
  int getHeight() const;
  int getWidth() const;
  Field &operator=(const Field &source);
};

// compare operator for Field class objects
bool operator==(const Field &x, const Field &y);

#endif