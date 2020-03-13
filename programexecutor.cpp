#include "programexecutor.h"

ProgramExecutor::ProgramExecutor(Adafruit_NeoPixel* physical_strip): physical_strip(physical_strip), selected(0), frame(0){
}

void ProgramExecutor::registerProgram(Program* program){
  this->programs.push_back(program);
}

void ProgramExecutor::nextProgram(){
  this->physical_strip->clear();
  this->physical_strip->show();
  
  this->selected = (this->selected + 1) % this->programs.size();
  this->frame = 0;
}

void ProgramExecutor::render(){
  this->programs[this->selected]->render(this->frame);
  this->physical_strip->show();
}
