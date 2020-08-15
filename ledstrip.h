#ifndef LEDSTRIP_H
#define LEDSTRIP_H

class LEDStrip {
public:
  virtual ~LEDStrip(){}
  virtual void setPixelColor(int x, int r, int g, int b) = 0;
  virtual void fill(int r, int g, int b) = 0;
  virtual void clear() = 0;
  virtual int numPixels() = 0;
};

#endif