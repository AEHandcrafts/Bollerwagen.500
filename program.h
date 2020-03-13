#ifndef PROGRAM_H
#define PROGRAM_H

#include "strip.h"

class Program {
  
protected:
  //TODO: define strips!! Strip* strip;

public:
  Program(Strip* strip);
  virtual ~Program(){};

  virtual void render(unsigned long frame) = 0;
  
};

#endif
