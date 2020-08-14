#ifndef PROGRAMEXECUTOR_H
#define PROGRAMEXECUTOR_H

#include "program.h"
#include "./util/array.h"

class ProgramExecutor {

private:
  Adafruit_NeoPixel* physical_strip;
  Array<Program*, 10> programs;

  int registeredPrograms;
  int selected;
  unsigned long frame;
  
public:
  ProgramExecutor(Adafruit_NeoPixel* physical_strip);

  void registerProgram(Program* program);
  void nextProgram();
  void render();
};

#endif
