#ifndef REQUEST_INTERFACE_HEADER
#define REQUEST_INTERFACE_HEADER
#include <iostream>

// request interface ancestor of Client class
class IRequest {
public:
  virtual void request() = 0;
};
#endif