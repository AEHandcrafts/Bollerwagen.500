#ifndef ALRBTMAPPINGSTRATEGY_H
#define ALRBTMAPPINGSTRATEGY_H

#include "mappingstrategy.h"

class ALRBTMappingStrategy : public MappingStrategy {
public:
  virtual ~ALRBTMappingStrategy(){}
  virtual int map(int x, int y, int width, int height) override {
      if(y % 2 == 0){
        return y * width + x;
      }else {
        return y * width + width - 1 - x;
      }
  }
};

#endif
