#include "Crouching.h"
#include "Idle.h"

void Crouching::idle(Animation* a)
{
	std::cout << "Crouch to Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}