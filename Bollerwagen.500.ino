#include <Adafruit_NeoPixel.h>
#include "Strip.h"
#include "Program.h"
#include "programexecutor.h"

Adafruit_NeoPixel strip(10, 5, NEO_GRB + NEO_KHZ800);

// TODO: create virtual sub-strips
Strip str1(&strip, 0, 5);
Strip str2(&strip, 6, 10);

// Parameter count wichtig!!!! -> dynamisches Array!
ProgramExecutor executor(1);

void setup() {
  // Setup Button
  attachInterrupt(0, onButtonClick, RISING);
   
  // Physical Strip init 
  strip.begin();
  strip.clear();
  strip.show();

  // Programs init
  // executor.registerProgram(new StaticColorProgram());
}

void loop() {
  // TODO: Voltmeter
  executor.render();
  strip.show();
}

void onButtonClick(){
  executor.nextProgram();
}
