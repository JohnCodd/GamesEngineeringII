#pragma once
#include "State.h"

class Shooting : public State
{
public:
	Shooting() {};
	~Shooting() {};
	void idle(Animation* a);
};