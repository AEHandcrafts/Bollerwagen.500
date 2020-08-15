#include <TimerOne.h>
#include "voltmeter.h"
#include "pwrmgr.h"

#include <Adafruit_NeoPixel.h>
#include "ledcontroller.h"
#include "virtualstrip.h"
#include "program.h"

#include "programs/noprogram.h"



Adafruit_NeoPixel physical_strip(10, 5, NEO_GRB + NEO_KHZ800);
LEDController led_controller(&physical_strip);

Voltmeter voltmeter(A0, 8, 4.98, 390000, 81800 + 10030);
PowerManager power_manager(10, &voltmeter, 10.5, 18);

// TODO: create virtual sub-strips
VirtualStrip str1(&physical_strip, 0, 5);
VirtualStrip str2(&physical_strip, 6, 10);

void setup() {
  Serial.begin(9600);

  // Voltmeter init
  voltmeter.begin();
  Serial.println("Initialized Voltmeter.");
  
  // PowerManager
  power_manager.begin();
  Serial.println("Initialized Power Manager.");
  
  // Setup Timer Interrupt for Power Manager
  Timer1.initialize(3 * 1000000);
  Timer1.attachInterrupt(onVoltmeterTimerInterrupt);
  Serial.println("Attatched Power Manager Timer Interrupt.");

  // Physical Strip init
  physical_strip.begin();
  physical_strip.clear();
  physical_strip.show();
  Serial.println("Initialized Physical LED Strip.");
  
  // Register Programs
  led_controller.registerProgram(new NoProgram());
  Serial.println("Registered Programs.");

  // Setup Button for Program switch
  attachInterrupt(digitalPinToInterrupt(3), onButtonClick, RISING);
  Serial.println("Attatched Button Interrupt.");
}

void loop() {
  led_controller.render();
}

void onButtonClick(){
  noInterrupts();
  Serial.println("Received Button Interrupt.");
  led_controller.nextProgram();
  interrupts();
}

void onVoltmeterTimerInterrupt(){
  noInterrupts();
  Serial.println("Received Voltmeter Timer Interrupt.");
  power_manager.update();
  interrupts();
}
