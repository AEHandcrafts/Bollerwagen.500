#ifndef PROGRAMEXECUTOR_H
#define PROGRAMEXECUTOR_H

#include "program.h"
#include <ArduinoSTL.h>

class ProgramExecutor {

private:
  std::vector<Program*> programs;
  
  int selected;
  unsigned long frame;
  
public:
  ProgramExecutor();

  void registerProgram(Program* program);
  void nextProgram();
  void render();
};

#endif
