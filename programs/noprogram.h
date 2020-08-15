#ifndef NOPROGRAM_H
#define NOPROGRAM_H

#include "../program.h"
#include <Arduino.h>

class NoProgram : public Program {
	
public:
	NoProgram(){}
	virtual ~NoProgram(){}

	virtual void begin() override {}
	virtual void render(unsigned long frame) override {}
	
};

#endif