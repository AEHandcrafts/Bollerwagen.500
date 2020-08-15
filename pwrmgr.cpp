#include "pwrmgr.h"
#include <Arduino.h>
#include <avr/sleep.h>

PowerManager::PowerManager(int digitalRelaisPin, Voltmeter* voltmeter, double shutdownVoltage, int underVoltageThreshold):
  digitalRelaisPin(digitalRelaisPin), voltmeter(voltmeter), shutdownVoltage(shutdownVoltage), underVoltageThreshold(underVoltageThreshold), underVoltageCounter(0) {}

void PowerManager::begin(){
  pinMode(this->digitalRelaisPin, OUTPUT);
  digitalWrite(this->digitalRelaisPin, HIGH);
}

void PowerManager::update(){  
  double voltage = this->voltmeter->measureVoltage();
  Serial.println("Measured Voltage: " + String(voltage) + "V");

  if (voltage > this->shutdownVoltage){
    this->underVoltageCounter = 0;
    Serial.println("Voltage established. Resetting UndervoltageCounter.");
  }else{
    this->underVoltageCounter++;
    Serial.println("UnderVoltage detected. UndervoltageCounter: " + String(this->underVoltageCounter) + " (turning off at " + String(this->underVoltageThreshold) + ")");
  }
  
  if(this->underVoltageCounter >= this->underVoltageThreshold){
    Serial.println("Shutting down...");
    digitalWrite(this->digitalRelaisPin, LOW);
    delay(5000);

    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_cpu();
  }
}
