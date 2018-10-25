#pragma once
#include "State.h"

class Meleeing : public State
{
public:
	Meleeing() {};
	~Meleeing() {};
	void idle(Animation* a);
};