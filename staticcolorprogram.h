#ifndef STATICCOLORPROGRAM_H
#define STATICCOLORPROGRAM_H

#include "program.h"
#include "ledcollection.h"

class StaticColorProgram : public Program {
private:
  LEDCollection* ledCollection;
  int r;
  int g;
  int b;
public:
  StaticColorProgram(LEDCollection* ledCollection, int r, int g, int b):
    ledCollection(ledCollection), r(r), g(g), b(b){
  }
  virtual ~StaticColorProgram(){}
  virtual void begin() override {
    this->ledCollection->ledStrip_front->fill(this->r, this->g, this->b);
    this->ledCollection->ledStrip_back->fill(this->r, this->g, this->b);
    this->ledCollection->ledStrip_bottom->fill(this->r, this->g, this->b);
    this->ledCollection->ledStripMatrix->fill(this->r, this->g, this->b);
  }
  virtual void render(unsigned long frame) override {}
};

#endif
