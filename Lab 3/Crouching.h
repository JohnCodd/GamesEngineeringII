#pragma once
#include "State.h"
class Crouching : public State
{
public:
	Crouching() {};
	~Crouching() {};
	void idle(Animation* a);
};