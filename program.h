#ifndef PROGRAM_H
#define PROGRAM_H

class Program {
public:
  virtual ~Program(){}
  virtual void begin() = 0;
  virtual void render(unsigned long frame) = 0;
};

#endif
