#include <Adafruit_NeoPixel.h>
#include "virtualstrip.h"
#include "program.h"
#include "programexecutor.h"

Adafruit_NeoPixel physical_strip(10, 5, NEO_GRB + NEO_KHZ800);
ProgramExecutor executor(&physical_strip);

// TODO: create virtual sub-strips
VirtualStrip str1(&physical_strip, 0, 5);
VirtualStrip str2(&physical_strip, 6, 10);

void setup() {
  // Setup Button
  attachInterrupt(digitalPinToInterrupt(2), onButtonClick, RISING);
   
  // Physical Strip init
  physical_strip.begin();
  physical_strip.clear();
  physical_strip.show();

  // Programs init
  // executor.registerProgram(new StaticColorProgram());
}

void loop() {
  // TODO: Voltmeter
  executor.render();
  physical_strip.show();
}

void onButtonClick(){
  executor.nextProgram();
}
