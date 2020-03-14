#include <Adafruit_NeoPixel.h>
#include "virtualstrip.h"
#include "program.h"
#include "programexecutor.h"

#include "programs/noprogram.h"

Adafruit_NeoPixel physical_strip(10, 5, NEO_GRB + NEO_KHZ800);
ProgramExecutor executor(&physical_strip);

// TODO: create virtual sub-strips
VirtualStrip str1(&physical_strip, 0, 5);
VirtualStrip str2(&physical_strip, 6, 10);

void setup() {
  Serial.begin(9600);
  
  // Setup Button
  attachInterrupt(digitalPinToInterrupt(2), onButtonClick, RISING);
  Serial.println("Attatched Button Interrupt.");
   
  // Physical Strip init
  physical_strip.begin();
  physical_strip.clear();
  physical_strip.show();
  Serial.println("Initialized Physical LED Strip.");

  // Register Programs
  executor.registerProgram(new NoProgram());
  Serial.println("Registered Programs.");
}

void loop() {
  executor.render();
  // TODO: Add Voltmeter
}

void onButtonClick(){
  Serial.println("Received Button Interrupt.");
  executor.nextProgram();
}
