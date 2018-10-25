#include "Shooting.h"
#include "Idle.h"

void Shooting::idle(Animation* a)
{
	std::cout << "Shoot to Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}