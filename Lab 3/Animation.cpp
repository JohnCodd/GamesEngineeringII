#include "Animation.h"	
#include "Idle.h"

Animation::Animation()
{
	current = new Idle();
}

void Animation::idle()
{
	current->idle(this);
}

void Animation::jumping()
{
	current->jumping(this);
}

void Animation::crouching()
{
	current->crouching(this);
}

void Animation::meleeing()
{
	current->meleeing(this);
}

void Animation::shooting()
{
	current->shooting(this);
}

void Animation::shielding()
{
	current->shielding(this);
}