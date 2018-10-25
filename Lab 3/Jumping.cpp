#include "Jumping.h"
#include "Idle.h"

void Jumping::idle(Animation* a)
{
	std::cout << "Jump to idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Jumping::shooting(Animation* a)
{
	std::cout << "Jump to shoot" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}