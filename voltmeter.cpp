#include "voltmeter.h"
#include <Arduino.h>

Voltmeter::Voltmeter(int voltMeterPin, int transistorPin, double arduinoU, long r1, long r2): voltMeterPin(voltMeterPin), transistorPin(transistorPin), arduinoU(arduinoU), r1(r1), r2(r2){
}

void Voltmeter::begin(){
  pinMode(this->transistorPin, OUTPUT);
  digitalWrite(this->transistorPin, LOW);
}

double Voltmeter::measureVoltage(){
  int anz = 5;
  double sum = 0;
  for(int i = 0; i<anz; i++){
    sum += this->measureVoltage_single();
  }
  return sum / (double)anz;
}

double Voltmeter::measureVoltage_single(){
  digitalWrite(this->transistorPin, HIGH);
  delay(2);
  int analogValue = analogRead(this->voltMeterPin);
  delay(2);
  digitalWrite(this->transistorPin, LOW);
  
  double measuredVoltage = (double)analogValue / 1023 * this->arduinoU;
  double current = measuredVoltage / (double)this->r2;
  double voltage = ((double)this->r1 + (double)this->r2) * current;

  return voltage - 0.15;
}
