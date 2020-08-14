#ifndef NOPROGRAM_H
#define NOPROGRAM_H

#include "../program.h"
#include <Arduino.h>

class NoProgram : public Program {
	
public:
	NoProgram(){}
	virtual ~NoProgram(){}

	virtual void render(unsigned long frame) {
		//delay(1000);
	}
	
};

#endif