#include "ledstripmatrixmirror.h"

LEDStripMatrixMirror::LEDStripMatrixMirror(ILEDStripMatrix* ledStripMatrix_1, ILEDStripMatrix* ledStripMatrix_2){
    // Only mirror if the strips are of the same size
    if(ledStripMatrix_1->numPixels() == ledStripMatrix_2->numPixels()){
        this->ledStripMatrix_1 = ledStripMatrix_1;
        this->ledStripMatrix_2 = ledStripMatrix_2;
    }
}

LEDStripMatrixMirror::~LEDStripMatrixMirror(){}

void LEDStripMatrixMirror::setPixelColor(int x, int r, int g, int b){
    this->ledStripMatrix_1->setPixelColor(x, r, g, b);
    this->ledStripMatrix_2->setPixelColor(x, r, g, b);
}

void LEDStripMatrixMirror::setPixelColor(int x, int y, int r, int g, int b){
    this->ledStripMatrix_1->setPixelColor(x, y, r, g, b);
    this->ledStripMatrix_2->setPixelColor(x, y, r, g, b);
}

void LEDStripMatrixMirror::fill(int r, int g, int b){
    this->ledStripMatrix_1->fill(r, g, b);
    this->ledStripMatrix_2->fill(r, g, b);
}

void LEDStripMatrixMirror::clear(){
    this->ledStripMatrix_1->clear();
    this->ledStripMatrix_2->clear();
}

int LEDStripMatrixMirror::numPixels(){
    return this->ledStripMatrix_1->numPixels();
}

int LEDStripMatrixMirror::width(){
    return this->ledStripMatrix_1->width();
}

int LEDStripMatrixMirror::height(){
    return this->ledStripMatrix_1->height();
}
