#include <Adafruit_NeoPixel.h>
#include "virtualstrip.h"
#include "program.h"
#include "programexecutor.h"
#include "voltmeter.h"

#include "programs/noprogram.h"

Adafruit_NeoPixel physical_strip(10, 5, NEO_GRB + NEO_KHZ800);
ProgramExecutor executor(&physical_strip);
Voltmeter voltmeter(A0, 2, 4.5, 390000, 81800 + 10030);

// TODO: create virtual sub-strips
VirtualStrip str1(&physical_strip, 0, 5);
VirtualStrip str2(&physical_strip, 6, 10);

void setup() {
  Serial.begin(9600);
  
  // Setup Button
  attachInterrupt(digitalPinToInterrupt(3), onButtonClick, RISING);
  Serial.println("Attatched Button Interrupt.");
   
  // Physical Strip init
  physical_strip.begin();
  physical_strip.clear();
  physical_strip.show();
  Serial.println("Initialized Physical LED Strip.");

  // Voltmeter init
  voltmeter.begin();
  Serial.println("Initialized Voltmeter.");

  // Register Programs
  executor.registerProgram(new NoProgram());
  Serial.println("Registered Programs.");
}

void loop() {
  double voltage = voltmeter.measureVoltage();
  Serial.println("Measured Voltage: " + String(voltage) + "V");
  
  if(voltage > 11.0){
    for(int i = 0; i < 600; i++){
      executor.render();
    } 
  }else{
    Serial.println("UnderVoltage detected. Rechecking in 3 Seconds...");
    delay(3000);
  }
}

void onButtonClick(){
  Serial.println("Received Button Interrupt.");
  executor.nextProgram();
}
