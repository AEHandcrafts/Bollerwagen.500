#ifndef PROGRAMEXECUTOR_H
#define PROGRAMEXECUTOR_H

#include "program.h"
#include <ArduinoSTL.h>

class ProgramExecutor {

private:
  Adafruit_NeoPixel* physical_strip;
  std::vector<Program*> programs;
  
  int selected;
  unsigned long frame;
  
public:
  ProgramExecutor(Adafruit_NeoPixel* physical_strip);

  void registerProgram(Program* program);
  void nextProgram();
  void render();
};

#endif
