#ifndef PROGRAM_H
#define PROGRAM_H

#include "virtualstrip.h"

class Program {
  
protected:
  //TODO: define strips!! Strip* strip;

public:
  Program(){}
  Program(VirtualStrip* strip){}
  virtual ~Program(){}

  virtual void render(unsigned long frame) = 0;
  
};

#endif
