#ifndef LEDCOLLECTION_H
#define LEDCOLLECTION_H

#include <Adafruit_NeoPixel.h>
#include "ledstrip.h"
#include "iledstripmatrix.h"

class LEDCollection {
public:
  LEDStrip* ledStrip_front;
  LEDStrip* ledStrip_back;
  LEDStrip* ledStrip_bottom;
  ILEDStripMatrix* ledStripMatrix;
private:
  Adafruit_NeoPixel* physical_strip;
public:
  LEDCollection();
  void begin();
  void clear();
  void show();
};

#endif
