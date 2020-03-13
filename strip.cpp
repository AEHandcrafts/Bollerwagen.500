#include "strip.h"

Strip::Strip(Adafruit_NeoPixel* strip, int start, int end): strip(strip), start(start), end(end){
}

void Strip::setPixelColor(int index, int r, int g, int b){
  int i = index + this->start;

  if(i <= this->end){
    this->strip->setPixelColor(i, r, g, b); 
  }
}

int Strip::count(){
  return (this->end - this->start) + 1;
}
