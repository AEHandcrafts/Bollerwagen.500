#ifndef STRIP_H
#define STRIP_H

#include <Adafruit_NeoPixel.h>

class Strip {

private:
  Adafruit_NeoPixel* strip = nullptr;
  int start;
  int end;

public:
  Strip(Adafruit_NeoPixel* strip, int start, int end);
  
  void setPixelColor(int index, int r, int g, int b);
  int count();
  
};

#endif
