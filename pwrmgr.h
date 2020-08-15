#ifndef PWRMGR_H
#define PWRMGR_H

#include "voltmeter.h"

class PowerManager {
  
private:
  int digitalRelaisPin;
  Voltmeter* voltmeter;
  double shutdownVoltage;
  int underVoltageThreshold;
  int underVoltageCounter;

public:
  PowerManager(int digitalRelaisPin, Voltmeter* voltmeter, double shutdownVoltage, int underVoltageThreshold);
  
  void begin();
  void update();
};

#endif
