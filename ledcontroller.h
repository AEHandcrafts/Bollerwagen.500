#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#include "ledcollection.h"
#include "program.h"
#include "array.h"

class LEDController {

private:
  LEDCollection* led_collection;
  Array<Program*, 10> programs;

  int registeredPrograms;
  int selected;
  unsigned long frame;
  
public:
  LEDController(LEDCollection* led_collection);

  void registerProgram(Program* program);
  void begin();
  void nextProgram();
  void render();
};

#endif
