#ifndef MAPPINGSTRATEGY_H
#define MAPPINGSTRATEGY_H

class MappingStrategy {
public:
  ~MappingStrategy(){}
  virtual int map(int x, int y, int width, int height) = 0;
};

#endif