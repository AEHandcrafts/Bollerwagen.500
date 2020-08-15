#include "ledcontroller.h"

LEDController::LEDController(LEDCollection* led_collection): led_collection(led_collection), registeredPrograms(0), selected(0), frame(0){
}

void LEDController::registerProgram(Program* program){
  this->programs[this->registeredPrograms] = program;
  this->registeredPrograms++;
}

void LEDController::nextProgram(){
  this->led_collection->clear();
  this->led_collection->show();
  Serial.println("Cleared the LED Strip.");
  
  this->selected = (this->selected + 1) % this->registeredPrograms;
  this->frame = 0;
  this->programs[this->selected]->begin();
  Serial.println("Switched the Program to " + String(this->selected));
}

void LEDController::render(){
  this->programs[this->selected]->render(this->frame);
  this->led_collection->show();
  this->frame++;
}
