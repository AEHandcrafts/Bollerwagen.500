#ifndef LEDSTRIPMIRROR_H
#define LEDSTRIPMIRROR_H

#include "ledstrip.h"

class LEDStripMirror : public LEDStrip {
private:
  LEDStrip* ledstrip_1;
  LEDStrip* ledstrip_2;
public:
  LEDStripMirror(LEDStrip* ledstrip_1, LEDStrip* ledstrip_2);
  virtual ~LEDStripMirror();
  virtual void setPixelColor(int x, int r, int g, int b) override;
  virtual void fill(int r, int g, int b) override;
  virtual void clear() override;
  virtual int numPixels() override;
};

#endif
