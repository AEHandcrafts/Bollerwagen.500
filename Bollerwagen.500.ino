#include <TimerOne.h>
#include "voltmeter.h"
#include "pwrmgr.h"

#include "ledcontroller.h"
#include "ledcollection.h"
#include "program.h"
#include "noprogram.h"
#include "staticcolorprogram.h"

LEDCollection led_collection;
LEDController led_controller(&led_collection);

Voltmeter voltmeter(A0, 8, 4.98, 390000, 81800 + 10030);
PowerManager power_manager(10, &voltmeter, 10.5, 18);

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
  led_collection.begin();
  led_collection.clear();
  led_collection.show();
  Serial.println("Initialized Physical LED Strip.");
  
  // Register Programs
  led_controller.registerProgram(new NoProgram());
  led_controller.registerProgram(new StaticColorProgram(&led_collection, 255, 255, 255));
  led_controller.registerProgram(new StaticColorProgram(&led_collection, 0, 0, 255));
  led_controller.begin();
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
