#include "ledstripmirror.h"

LEDStripMirror::LEDStripMirror(LEDStrip* ledstrip_1, LEDStrip* ledstrip_2){
    // Only mirror if the strips are of the same size
    if(ledstrip_1->numPixels() == ledstrip_2->numPixels()){
        this->ledstrip_1 = ledstrip_1;
        this->ledstrip_2 = ledstrip_2;
    }
}

LEDStripMirror::~LEDStripMirror(){}

void LEDStripMirror::setPixelColor(int x, int r, int g, int b){
    this->ledstrip_1->setPixelColor(x, r, g, b);
    this->ledstrip_2->setPixelColor(x, r, g, b);
}

void LEDStripMirror::fill(int r, int g, int b){
    this->ledstrip_1->fill(r, g, b);
    this->ledstrip_2->fill(r, g, b);
}

void LEDStripMirror::clear(){
    this->ledstrip_1->clear();
    this->ledstrip_2->clear();
}

int LEDStripMirror::numPixels(){
    return this->ledstrip_1->numPixels();
}
