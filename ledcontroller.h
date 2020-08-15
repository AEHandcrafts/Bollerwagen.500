#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#include "program.h"
#include "./util/array.h"

class LEDController {

private:
  Adafruit_NeoPixel* physical_strip;
  Array<Program*, 10> programs;

  int registeredPrograms;
  int selected;
  unsigned long frame;
  
public:
  LEDController(Adafruit_NeoPixel* physical_strip);

  void registerProgram(Program* program);
  void nextProgram();
  void render();
};

#endif
