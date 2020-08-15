#include "ledstripmatrix.h"

LEDStripMatrix::LEDStripMatrix(int width, int height, LEDStrip* ledStrip, MappingStrategy* mappingStrategy):
  m_width(width), m_height(height), ledStrip(ledStrip), mappingStrategy(mappingStrategy){
}

LEDStripMatrix::~LEDStripMatrix(){}

void LEDStripMatrix::setPixelColor(int x, int r, int g, int b){
  this->ledStrip->setPixelColor(x, r, g, b);
}

void LEDStripMatrix::setPixelColor(int x, int y, int r, int g, int b){
  int index = this->mappingStrategy->map(x, y, this->m_width, this->m_height);
  this->ledStrip->setPixelColor(index, r, g, b);
}

void LEDStripMatrix::fill(int r, int g, int b){
  this->ledStrip->fill(r, g, b);
}

void LEDStripMatrix::clear(){
  this->ledStrip->clear();
}

int LEDStripMatrix::numPixels(){
  return this->ledStrip->numPixels();
}

int LEDStripMatrix::width(){
  return this->m_width;
}

int LEDStripMatrix::height(){
  return this->m_height;
}
