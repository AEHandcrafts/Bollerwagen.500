#include "programexecutor.h"

ProgramExecutor::ProgramExecutor(Adafruit_NeoPixel* physical_strip): physical_strip(physical_strip), registeredPrograms(0), selected(0), frame(0){
}

void ProgramExecutor::registerProgram(Program* program){
  this->programs[this->registeredPrograms] = program;
  this->registeredPrograms++;
}

void ProgramExecutor::nextProgram(){
  this->physical_strip->clear();
  this->physical_strip->show();
  Serial.println("Cleared the LED Strip.");
  
  this->selected = (this->selected + 1) % this->registeredPrograms;
  this->frame = 0;
  Serial.println("Switched the Program to " + String(this->selected));
}

void ProgramExecutor::render(){
  this->programs[this->selected]->render(this->frame);
  this->physical_strip->show();
  this->frame++;
}
