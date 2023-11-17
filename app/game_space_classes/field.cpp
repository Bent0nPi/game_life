#include "field.h"
#include "../utils/exceptions.h"
#include <iostream>

Field::Field() {
  int standartSize = 10;
  height_ = standartSize;
  width_ = standartSize;
  cells_ = new char *[standartSize];
  for (int i = 0; i < standartSize; i++) {
    cells_[i] = new char[standartSize];
    for (int j = 0; j < standartSize; j++) {
      cells_[i][j] = 0;
    }
  }
}

Field::Field(int height, int width) {
  cells_ = new char *[height];
  for (int i = 0; i < height; i++) {
    cells_[i] = new char[width];
    for (int j = 0; j < width; j++) {
      cells_[i][j] = 0;
    }
  }
  height_ = height;
  width_ = width;
}

Field::Field(int height, int width, int **data) {
  cells_ = new char *[height];
  for (int i = 0; i < height; i++) {
    cells_[i] = new char[width];
    for (int j = 0; j < width; j++) {
      cells_[i][j] = data[i][j];
    }
  }
  height_ = height;
  width_ = width;
}

Field::Field(const Field &sample) {
  height_ = sample.height_;
  width_ = sample.width_;
  cells_ = new char *[height_];
  for (int i = 0; i < height_; i++) {
    cells_[i] = new char[width_];
    for (int j = 0; j < width_; j++) {
      cells_[i][j] = sample.cells_[i][j];
    }
  }
}

Field::~Field() {
  for (int i = 0; i < height_; i++) {
    delete[] cells_[i];
  }
  delete[] cells_;
}

// equating operator
Field &Field::operator=(const Field &source) {
  // avoid itself equating
  if (source == *this) {
    return *this;
  }
  // free last memory
  for (int i = 0; i < height_; i++) {
    delete[] cells_[i];
  }
  delete[] cells_;
  // copy values from source object
  height_ = source.height_;
  width_ = source.width_;
  cells_ = new char *[height_];
  // initialize array
  for (int i = 0; i < height_; i++) {
    cells_[i] = new char[width_];
    for (int j = 0; j < width_; j++) {
      cells_[i][j] = source.cells_[i][j];
    }
  }
  return *this;
}
// apeal to cell by indexes
char &Field::at(int firstIndex, int secondIndex) {
  if (firstIndex >= height_ || firstIndex < 0 || secondIndex >= width_ ||
      secondIndex < 0) {
    throw GameLogicException("going out of field bounds");
  }
  return cells_[firstIndex][secondIndex];
}
// apeal to cell for const objects
const char &Field::at(int firstIndex, int secondIndex) const {
  if (firstIndex >= height_ || firstIndex < 0 || secondIndex >= width_ ||
      secondIndex < 0) {
    throw GameLogicException("going out of field bounds");
  }
  return cells_[firstIndex][secondIndex];
}

// getters
int Field::getHeight() const { return height_; }

int Field::getWidth() const { return width_; }

// comparing operator
bool operator==(const Field &x, const Field &y) {
  // check fields of object
  if (x.getHeight() != y.getHeight() || x.getWidth() != y.getWidth()) {
    return false;
  }
  // check each cell's value
  int matrixHeight = x.getHeight(), matrixWidth = x.getWidth();
  for (int i = 0; i < matrixHeight; i++) {
    for (int j = 0; j < matrixWidth; j++) {
      if (x.at(i, j) != y.at(i, j)) {
        return false;
      }
    }
  }
  return true;
}