#ifndef EXECUTE_INTERFACE_HEADER
#define EXECUTE_INTERFACE_HEADER
#include <iostream>

// execute interface ancestor of Client class
class IExecute {
public:
  virtual void execute() = 0;
};

#endif