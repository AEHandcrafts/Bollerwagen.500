#ifndef PROGRAMEXECUTOR_H
#define PROGRAMEXECUTOR_H

#include "Program.h"

class ProgramExecutor {

private:
  Program** programs;
  int count_programs;
  
  int selected;
  unsigned long frame;
  
public:
  ProgramExecutor(int count);
  ~ProgramExecutor();

  void registerProgram(Program* program);
  void nextProgram();
  void render();
};

#endif
