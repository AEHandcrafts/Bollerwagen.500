#ifndef LEDSTRIPMATRIXMIRROR_H
#define LEDSTRIPMATRIXMIRROR_H

#include "iledstripmatrix.h"

class LEDStripMatrixMirror : public ILEDStripMatrix {
private:
  ILEDStripMatrix* ledStripMatrix_1;
  ILEDStripMatrix* ledStripMatrix_2;
public:
  LEDStripMatrixMirror(ILEDStripMatrix* ledStripMatrix_1, ILEDStripMatrix* ledStripMatrix_2);
  virtual ~LEDStripMatrixMirror();
  virtual void setPixelColor(int x, int r, int g, int b) override;
  virtual void setPixelColor(int x, int y, int r, int g, int b) override;
  virtual void fill(int r, int g, int b) override;
  virtual void clear() override;
  virtual int numPixels() override;
  virtual int width() override;
  virtual int height() override;
};

#endif
