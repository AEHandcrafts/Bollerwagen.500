#ifndef VOLTMETER_H
#define VOLTMETER_H

class Voltmeter {

private:
  int voltMeterPin;
  int transistorPin;
  double arduinoU;
  long r1;
  long r2;
  
public:
  Voltmeter(int voltMeterPin, int transistorPin, double arduinoU, long r1, long r2);
  void begin();
  double measureVoltage();

private:
  double measureVoltage_single();
};

#endif
