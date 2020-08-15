#ifndef LEDSTRIPMATRIX_H
#define LEDSTRIPMATRIX_H

#include "iledstripmatrix.h"
#include "ledstrip.h"
#include "mappingstrategy.h"

class LEDStripMatrix : public ILEDStripMatrix {
private:
  int m_width;
  int m_height;
  LEDStrip* ledStrip;
  MappingStrategy* mappingStrategy;
public:
  LEDStripMatrix(int width, int height, LEDStrip* ledStrip, MappingStrategy* mappingStrategy);
  virtual ~LEDStripMatrix();
  virtual void setPixelColor(int x, int r, int g, int b) override;
  virtual void setPixelColor(int x, int y, int r, int g, int b) override;
  virtual void fill(int r, int g, int b) override;
  virtual void clear() override;
  virtual int numPixels() override;
  virtual int width() override;
  virtual int height() override;
};

#endif
