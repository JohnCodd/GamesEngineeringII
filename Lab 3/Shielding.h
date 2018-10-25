#pragma once
#include "State.h"
class Shielding : public State
{
public:
	Shielding() {};
	~Shielding() {};
	void idle(Animation* a);
};