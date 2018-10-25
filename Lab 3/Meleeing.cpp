#include "Meleeing.h"
#include "Idle.h"

void Meleeing::idle(Animation* a)
{
	std::cout << "Melee to Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}