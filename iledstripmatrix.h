#ifndef ILEDSTRIPMATRIX_H
#define ILEDSTRIPMATRIX_H

#include "ledstrip.h"

class ILEDStripMatrix : public LEDStrip {
public:
  virtual ~ILEDStripMatrix(){}
  virtual void setPixelColor(int x, int r, int g, int b) = 0;
  virtual void setPixelColor(int x, int y, int r, int g, int b) = 0;
  virtual void fill(int r, int g, int b) = 0;
  virtual void clear() = 0;
  virtual int numPixels() = 0;
  virtual int width() = 0;
  virtual int height() = 0;
};

#endif
