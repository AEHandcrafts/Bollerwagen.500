#ifndef VLEDSTRIP_H
#define VLEDSTRIP_H

#include "ledstrip.h"
#include <Adafruit_NeoPixel.h>

class VLEDStrip : public LEDStrip {
private:
  Adafruit_NeoPixel* physical_strip;
  int start;
  int end;
public:
  VLEDStrip(Adafruit_NeoPixel* physical_strip, int start, int end);
  virtual ~VLEDStrip();
  virtual void setPixelColor(int x, int r, int g, int b) override;
  virtual void fill(int r, int g, int b) override;
  virtual void clear() override;
  virtual int numPixels() override;
};

#endif
