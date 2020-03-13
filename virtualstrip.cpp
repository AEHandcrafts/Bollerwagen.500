#include "virtualstrip.h"

VirtualStrip::VirtualStrip(Adafruit_NeoPixel* strip, int start, int end): strip(strip), start(start), end(end){
}

void VirtualStrip::setPixelColor(int index, int r, int g, int b){
  int i = index + this->start;

  if(i >= this->start && i <= this->end){
    this->strip->setPixelColor(i, r, g, b);
  }
}

int VirtualStrip::count(){
  return (this->end - this->start) + 1;
}
