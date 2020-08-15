#include "ledcollection.h"

#include "vledstrip.h"
#include "ledstripmatrix.h"
#include "ledstripmirror.h"
#include "ledstripmatrixmirror.h"
#include "alrbtmappingstrategy.h"

LEDCollection::LEDCollection(){
  // TODO: init the strips properly
  this->physical_strip = new Adafruit_NeoPixel(10, 5, NEO_GRB + NEO_KHZ800);
  this->ledStrip_front  = new LEDStripMirror(new VLEDStrip(physical_strip, 0, 1), new VLEDStrip(physical_strip, 0, 1));
  this->ledStrip_back   = new LEDStripMirror(new VLEDStrip(physical_strip, 0, 1), new VLEDStrip(physical_strip, 0, 1));
  this->ledStrip_bottom = new LEDStripMirror(new VLEDStrip(physical_strip, 0, 1), new VLEDStrip(physical_strip, 0, 1));
  this->ledStripMatrix  = new LEDStripMatrixMirror(new LEDStripMatrix(13, 8, new VLEDStrip(physical_strip, 0, 1), new ALRBTMappingStrategy()), new LEDStripMatrix(13, 8, new VLEDStrip(physical_strip, 0, 1), new ALRBTMappingStrategy()));
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
