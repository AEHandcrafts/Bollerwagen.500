#ifndef NOPROGRAM_H
#define NOPROGRAM_H

#include "../program.h"

class NoProgram : public Program {
	
public:
	NoProgram(){}
	virtual ~NoProgram(){}

	virtual void render(unsigned long frame) {}
	
};

#endif