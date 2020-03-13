#include "programexecutor.h"

ProgramExecutor::ProgramExecutor(): selected(0), frame(0){
}

void ProgramExecutor::registerProgram(Program* program){
  this->programs.push_back(program);
}

void ProgramExecutor::nextProgram(){
  this->selected = (this->selected + 1) % this->programs.size();
  this->frame = 0;
}

void ProgramExecutor::render(){
  this->programs[this->selected]->render(this->frame);
}
