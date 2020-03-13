#include "ProgramExecutor.h"

ProgramExecutor::ProgramExecutor(int count): selected(0), frame(0), count_programs(0), programs(new Program*[count]){
}

ProgramExecutor::~ProgramExecutor(){
  delete[] this->programs;
}

void ProgramExecutor::registerProgram(Program* program){
  this->programs[this->count_programs] = program;
  this->count_programs++;
}

void ProgramExecutor::nextProgram(){
  this->selected = (this->selected + 1) % this->count_programs;
  this->frame = 0;
}

void ProgramExecutor::render(){
  this->programs[this->selected]->render(this->frame);
}
