#ifndef VIRTUALSTRIP_H
#define VIRTUALSTRIP_H

#include <Adafruit_NeoPixel.h>

class VirtualStrip {

private:
  Adafruit_NeoPixel* strip;
  int start;
  int end;

public:
  VirtualStrip(Adafruit_NeoPixel* strip, int start, int end);
  
  void setPixelColor(int index, int r, int g, int b);
  int count();
  
};

#endif
