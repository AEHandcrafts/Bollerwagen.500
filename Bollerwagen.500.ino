#include <Adafruit_NeoPixel.h>
#include <TimerOne.h>
#include <avr/sleep.h>
#include "virtualstrip.h"
#include "program.h"
#include "programexecutor.h"
#include "voltmeter.h"

#include "programs/noprogram.h"

Adafruit_NeoPixel physical_strip(10, 5, NEO_GRB + NEO_KHZ800);
ProgramExecutor executor(&physical_strip);

Voltmeter voltmeter(A0, 8, 4.98, 390000, 81800 + 10030);

// TODO: create virtual sub-strips
VirtualStrip str1(&physical_strip, 0, 5);
VirtualStrip str2(&physical_strip, 6, 10);

double shutdownVoltage = 10.5;
int shutdownTime = 4; // shutdownTime times 3 secondons under voltage

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

  // Setup Timer Interrupt
  Timer1.initialize(3 * 1000000);
  Timer1.attachInterrupt(onVoltmeterTimerInterrupt);
  Serial.println("Attatched Voltmeter Timer Interrupt.");

  // Relais
  pinMode(10, OUTPUT);
  
  // Register Programs
  executor.registerProgram(new NoProgram());
  Serial.println("Registered Programs.");
}

int underVoltageCounter = 0;
void loop() {
  executor.render();
}

void onButtonClick(){
  noInterrupts();
  Serial.println("Received Button Interrupt.");
  executor.nextProgram();
  interrupts();
}

void onVoltmeterTimerInterrupt(){
  Serial.println("Received Voltmeter Timer Interrupt.");
  
  double voltage = voltmeter.measureVoltage();
  Serial.println("Measured Voltage: " + String(voltage) + "V");

  if (voltage > shutdownVoltage){
    underVoltageCounter = 0;
  }else{
    underVoltageCounter++;    
    Serial.println("UnderVoltage detected: " + String(underVoltageCounter));
  }
  
  if(underVoltageCounter < shutdownTime){
    digitalWrite(10, HIGH);
  }else{
    Serial.println("Shutting down...");
    digitalWrite(10, LOW);

    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_cpu();
    sleep_disable(); 
  }
}
