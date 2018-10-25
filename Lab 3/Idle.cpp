#include "Idle.h"
#include "Jumping.h"
#include "Meleeing.h"
#include "Shooting.h"
#include "Crouching.h"
#include "Shielding.h"

void Idle::jumping(Animation* a)
{
	std::cout << "Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Idle::meleeing(Animation* a)
{
	std::cout << "Meleeing" << std::endl;
	a->setCurrent(new Meleeing());
	delete this;
}

void Idle::shielding(Animation* a)
{
	std::cout << "Shielding" << std::endl;
	a->setCurrent(new Shielding());
	delete this;
}

void Idle::crouching(Animation* a)
{
	std::cout << "Crouching" << std::endl;
	a->setCurrent(new Crouching());
	delete this;
}

void Idle::shooting(Animation* a)
{
	std::cout << "Firing" << std::endl;
	a->setCurrent(new Shooting());
	delete this;
}