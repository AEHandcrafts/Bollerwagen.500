#include "vledstrip.h"

VLEDStrip::VLEDStrip(Adafruit_NeoPixel* physical_strip, int start, int end):
  physical_strip(physical_strip), start(start), end(end){
}

VLEDStrip::~VLEDStrip(){
}

void VLEDStrip::setPixelColor(int x, int r, int g, int b){
  if((this->end - this->start) >= 0){
    x += this->start;
    if(x >= this->start && x <= this->end){
      this->physical_strip->setPixelColor(x, r, g, b);
    }
  }else{
    x += this->end;
    if(x >= this->end && x <= this->start){
      this->physical_strip->setPixelColor(x, r, g, b);
    }
  }
}

void VLEDStrip::fill(int r, int g, int b){
  uint32_t color = this->physical_strip->Color(r, g, b);
  if((this->end - this->start) >= 0){
    this->physical_strip->fill(color, this->start, this->end);
  }else{
    this->physical_strip->fill(color, this->end, this->start);
  }
}

void VLEDStrip::clear(){
  this->fill(0, 0, 0);
}

int VLEDStrip::numPixels(){
  return abs(this->end - this->start);
}
