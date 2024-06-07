#include "ledcollection.h"

#include "vledstrip.h"
#include "ledstripmatrix.h"
#include "ledstripmirror.h"
#include "ledstripmatrixmirror.h"
#include "alrbtmappingstrategy.h"

LEDCollection::LEDCollection(){
  this->physical_strip = new Adafruit_NeoPixel(314, 5, NEO_GRB + NEO_KHZ800);
  
  this->ledStrip_front  = new LEDStripMirror(new VLEDStrip(physical_strip, 304, 296), new VLEDStrip(physical_strip, 305, 313));
  this->ledStrip_back   = new LEDStripMirror(new VLEDStrip(physical_strip, 191, 183), new VLEDStrip(physical_strip, 174, 182));
  this->ledStrip_bottom = new LEDStripMirror(new VLEDStrip(physical_strip, 0, 34), new VLEDStrip(physical_strip, 69, 35));
  this->ledStripMatrix  = new LEDStripMatrixMirror(new LEDStripMatrix(13, 8, new VLEDStrip(physical_strip, 192, 295), new ALRBTMappingStrategy()), new LEDStripMatrix(13, 8, new VLEDStrip(physical_strip, 70, 173), new ALRBTMappingStrategy()));
}

void LEDCollection::begin(){
  this->physical_strip->begin();
}

void LEDCollection::clear(){
  this->physical_strip->clear();
}

void LEDCollection::show(){
  this->physical_strip->show();
}
