#include "Shielding.h"
#include "Idle.h"

void Shielding::idle(Animation* a)
{
	std::cout << "Shield to Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}