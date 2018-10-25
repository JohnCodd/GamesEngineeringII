#pragma once
#include "State.h"

class Idle : public State
{
public:
	Idle() {};
	~Idle() {};
	void jumping(Animation* a);
	void meleeing(Animation* a);
	void crouching(Animation* a);
	void shielding(Animation* a);
	void shooting(Animation* a);
};