#ifndef NOPROGRAM_H
#define NOPROGRAM_H

#include "program.h"

class NoProgram : public Program {
public:
	virtual void begin() override {}
	virtual void render(unsigned long frame) override {}
};

#endif
